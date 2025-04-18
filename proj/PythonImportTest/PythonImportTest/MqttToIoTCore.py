import paho.mqtt.client as mqtt
import ssl
import time
import json
import os
import base64

class AWSIoTClient:

    def __init__(self, endpoint, client_id, topic, ca_cert, cert_file, private_key, device_dir):
        """
        AWS IoT Core MQTT 클라이언트 초기화
        :param endpoint: AWS IoT Core Endpoint
        :param client_id: AWS Client ID (Custom)
        :param topic: MQTT Topic
        :param ca_cert: CA Certificate Directory Address 
        :param cert_file: Cert File Directory Address
        :param private_key: Private Key Directory Address
        """
        print("Create AWS IoT Client...")
        
        self.endpoint = endpoint
        self.client_id = client_id
        self.topic = topic
        self.ca_cert = ca_cert
        self.cert_file = cert_file
        self.private_key = private_key
        self.device_dir = device_dir
        
        print("Endpoint: ", self.endpoint)
        print("Client ID: ", self.client_id)
        print("Topic: ", self.topic)
        print("CA Cert: ", self.ca_cert)
        print("Cert File: ", self.cert_file)
        print("Private Key: ", self.private_key)
        print("Device Directory: ", self.device_dir)
        
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
            print("Connection to ", self.endpoint,"/", self.topic, ": Success")
            self.client.subscribe(self.topic)
        else:
            print("Connection to ", self.endpoint,"/", self.topic, f": Failure (RC: {rc})")

    def on_message(self, client, userdata, msg):
        # Call when receiving MQTT message
        print("Message from ", self.endpoint, f": {msg.topic} -> {msg.payload.decode()}")
        
        message = dict(json.loads(msg.payload.decode()))
        if message.get("request") is None: 
            return
        
        request = message["request"]
        
        if request == "transfer":
            file = message["file"]
            
            filename = file["name"]
            filecontent = base64.b64decode(file["content"])

            os.makedirs(self.device_dir, exist_ok=True)
            file_path = os.path.join(self.device_dir, filename)
               
            with open(file_path, "wb") as file:
                file.write(filecontent)
        elif request == "printstart":
            print("Request to PrintStart!!!!!")
            
    def connect(self):
        # Connect AWS IoT Core
        print("Try to Connection to", self.endpoint, "/", self.topic, "...")
        self.client.connect(self.endpoint, 8883, 60)
        self.client.loop_start()
    
        time.sleep(5)
        
        print("Connection End - Endpoint: ", self.endpoint, "/ topic", self.topic)

    def publish(self, message):
        # Send MQTT message
        payload = json.dumps(message)
        self.client.publish(self.topic, payload)
        print("Sent Message to ", self.endpoint, "/", self.topic, f": {payload}")

    def disconnect(self):
        # Disconnect to AWS IoT Core
        self.client.loop_stop()
        self.client.disconnect()
        print("Disconnection to ", self.endpoint,"/", self.topic, ": Success")

