import paho.mqtt.client as mqtt
import ssl
import time
import json
import os
import base64
import requests

class AWSIoTClient:

    def __init__(self, iot_endpoint, client_id, topic, ca_cert, cert_file, private_key, device_dir, recipe_dir, request_file, api_endpoint):
        """
        AWS IoT Core MQTT 클라이언트 초기화
        :param endpoint: AWS IoT Core Endpoint
        :param client_id: AWS Client ID (Custom)
        :param topic: MQTT Topic
        :param ca_cert: CA Certificate Directory Address 
        :param cert_file: Cert File Directory Address
        :param private_key: Private Key Directory Address
        """
        print("Create MQTT Client...")
        
        self.iot_endpoint = iot_endpoint
        self.client_id = client_id
        self.topic = topic
        self.ca_cert = ca_cert
        self.cert_file = cert_file
        self.private_key = private_key
        self.device_dir = device_dir
        self.recipe_dir = recipe_dir
        self.request_file = request_file
        self.api_endpoint = api_endpoint
        
        print("IoT Core Endpoint: ", self.iot_endpoint)
        print("Client ID: ", self.client_id)
        print("Topic: ", self.topic)
        print("CA Cert: ", self.ca_cert)
        print("Cert File: ", self.cert_file)
        print("Private Key: ", self.private_key)
        print("Device Data Directory: ", self.device_dir)
        print("Device Recipe Directory: ", self.recipe_dir)
        print("Device Request File: ", self.request_file)
        print("API Gateway Endpoint: ", self.api_endpoint)
        
        self.client = mqtt.Client(client_id=self.client_id)
        print("Create MQTT Client Successfully!!")
        
        # TLS 설정
        self.client.tls_set(ca_certs=self.ca_cert,
                            certfile=self.cert_file,
                            keyfile=self.private_key,
                            tls_version=ssl.PROTOCOL_TLSv1_2)
        print("Set TLS (CA Cert / Cert File / Private Key / TLS Version) Successfully!!")
        
        # 콜백 함수 설정
        self.client.on_connect = self.on_connect
        self.client.on_message = self.on_message

    def on_connect(self, client, userdata, flags, rc):
        # Call when connected to AWS IoT Core
        if rc == 0:
            print("Connection to ", self.iot_endpoint,"/", self.topic, ": Success")
            self.client.subscribe(self.topic)
        else:
            print("Connection to ", self.iot_endpoint,"/", self.topic, f": Failure (RC: {rc})")

    def get_presigned_url(self, method, key):
        # key example = 'X1/1/files/test.slice'
        
        key_ls = ((str)(key)).split('/')
        
        devtype = key_ls[0]; devid = key_ls[1]
        if len(key_ls) > 3: data_name = key_ls[2]+"/"+key_ls[3]
        else: data_name = key_ls[2]
        
        response = requests.post(self.api_endpoint, 
            json={
                "action": "get_presigned_url", 
                "device":{
                    "type": devtype, 
                    "id": devid
                }, 
                "data":{
                    "name": data_name, 
                    "method": method
                }
            }
        )
        if response.status_code == 200: return response.json()
        else: return None
        
    def get_file_from_presigned_url(self, presigned_url):
        response = requests.get(presigned_url)
        if response.status_code == 200: return response.json()
        else: return None
        
    def put_file_to_presigned_url(self, presigned_url, json_data):
        response = requests.put(url=presigned_url,json=json_data)
        if response.status_code == 200: return True
        else: return False
        
    def on_message(self, client, userdata, msg):
        # Call when receiving MQTT message
        print("Message from ", self.iot_endpoint, f": {msg.topic} -> {msg.payload.decode()}")
        
        message = dict(json.loads(msg.payload.decode()))
        if message.get("request") is None: 
            return
        
        request = message["request"]
        
        if request == "file-transfer":
            data = message["data"]
            
            presigned_url = self.get_presigned_url(method="get_object",key=data["content"])
            if presigned_url is not None:
                content = self.get_file_from_presigned_url(presigned_url=presigned_url)
                
                if content is not None:
                    
                    output_file_path = ""
                    
                    if content["type"] == "data":
                        output_file_path = self.device_dir+"/"+content["name"]
                    elif content["type"] == "recipe":
                        output_file_path = self.recipe_dir+"/"+content["name"]

                    decoded_bytes = base64.b64decode(content["content"])

                    with open(output_file_path, 'wb') as f: f.write(decoded_bytes)
            else:
                return
            
        elif request == "allow-remote-control":
            with open(self.request_file, 'r', encoding='utf-8') as file:
                requestlist_dic = json.load(file)
                
            requestlist_dic["request-list"].append({"type": "allow-remote-control"})
            
            with open(self.request_file, 'w', encoding='utf-8') as file:
                json.dump(requestlist_dic, file, indent=4, ensure_ascii=False)
                
        elif request == "print-start":
            data = message["data"]
            
            pdata = data["data"]
            pecipe = data["recipe"]
            
            with open(self.request_file, 'r', encoding='utf-8') as file:
                requestlist_dic = json.load(file)
                
            requestlist_dic["request-list"].append({"type": "print-start", "data": pdata, "recipe": pecipe})
            
            with open(self.request_file, 'w', encoding='utf-8') as file:
                json.dump(requestlist_dic, file, indent=4, ensure_ascii=False)
         
    def connect(self):
        # Connect AWS IoT Core
        print("Try to Connection to", self.iot_endpoint, "/", self.topic, "...")
        self.client.connect(self.iot_endpoint, 8883, 60)
        self.client.loop_start()
    
        time.sleep(5)
        
        print("Connection End - Endpoint: ", self.iot_endpoint, "/ topic", self.topic)

    def publish(self, message):
        # Send MQTT message
        payload = json.dumps(message)
        self.client.publish(self.topic, payload)
        print("Sent Message to ", self.iot_endpoint, "/", self.topic, f": {payload}")

    def disconnect(self):
        # Disconnect to AWS IoT Core
        self.client.loop_stop()
        self.client.disconnect()
        print("Disconnection to ", self.iot_endpoint,"/", self.topic, ": Success")