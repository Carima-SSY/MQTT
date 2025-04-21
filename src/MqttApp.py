import MqttToIoTCore
import time
import random
import json
# ================================
# Application Code (MQTT ~ IoT Core)
# ================================

def get_config_info():
    with open('./static/config.json', 'r', encoding='utf-8') as file:
        config_content = json.load(file) 
    return config_content 

def get_print_data():
    with open('./static/pdata.json', 'r', encoding='utf-8') as file:
        pdata_content = json.load(file) 
    return pdata_content 

def get_print_recipe():
    with open('./static/precipe.json', 'r', encoding='utf-8') as file:
        precipe_content = json.load(file) 
    return precipe_content 

def get_sensor_status():
    with open('./static/sensor.json', 'r', encoding='utf-8') as file:
        sstatus_content = json.load(file) 
    return sstatus_content 

def get_device_status():
    with open('./static/dstatus.json', 'r', encoding='utf-8') as file:
        dstatus_content = json.load(file) 
    return dstatus_content 

def get_device_auth():
    with open('./static/auth.json', 'r', encoding='utf-8') as file:
        auth_content = json.load(file) 
    return auth_content 

def get_device_alarm():
    with open('./static/alarm.json', 'r', encoding='utf-8') as file:
        alarm_content = json.load(file) 
    return alarm_content 

def init_storage(mqtt_client, device_type, device_id, device_auth, sensor_status, device_status, print_data, print_recipe, device_alarm):
    mqtt_client.publish({"target": "storage","action": "device-auth","device":{"type": device_type,"id": device_id},"data":{"content": device_auth}})
    mqtt_client.publish({"target": "storage","action": "sensor-status","device":{"type": device_type,"id": device_id},"data":{"content": sensor_status}})
    mqtt_client.publish({"target": "storage","action": "device-status","device":{"type": device_type,"id": device_id},"data":{"content": device_status}})
    mqtt_client.publish({"target": "storage","action": "print-data","device":{"type": device_type,"id": device_id},"data":{"content": print_data}})
    mqtt_client.publish({"target": "storage","action": "print-recipe","device":{"type": device_type,"id": device_id},"data":{"content": print_recipe}})
    #mqtt_client.publish({"target": "storage","action": "device-alarm","device":{"type": device_type,"id": device_id},"data":{"content": device_alarm}})
    
if __name__ == "__main__":
    config_content = get_config_info()
    
    IOT_END_POINT = config_content["IoTCore"]["end_point"]
    CLIENT_ID = config_content["IoTCore"]["client_id"]
        
    CA_CERT = config_content["IoTCore"]["ca_cert"]
    CERT_FILE = config_content["IoTCore"]["cert_file"]
    PRIVATE_KEY = config_content["IoTCore"]["private_key"]
    
    DEV_TYPE = config_content["device"]["type"]
    DEV_ID = config_content["device"]["id"]
    
    TOPIC = DEV_TYPE+"/"+DEV_ID
    
    DATA_DIR = config_content["dir"]["data"]
    RECIPE_DIR = config_content["dir"]["recipe"]
    
    REQUEST_FILE = config_content["request_file"]
    
    APP_VERSION = config_content["App-Version"]
    
    APIG_END_POINT = config_content["APIGateway"]["end_point"]
    
    mqtt_client = MqttToIoTCore.AWSIoTClient(IOT_END_POINT, CLIENT_ID, TOPIC, CA_CERT, CERT_FILE, PRIVATE_KEY, DATA_DIR, RECIPE_DIR, REQUEST_FILE,   APIG_END_POINT)
    
    mqtt_client.connect()
    
    time.sleep(5)
    
    sensor_status = get_sensor_status()
    device_status = get_device_status()
    
    print_data = get_print_data()
    print_recipe = get_print_recipe()
    
    device_auth = get_device_auth()
    device_alarm = get_device_alarm()
    
    init_storage(mqtt_client=mqtt_client, device_type=DEV_TYPE, device_id=DEV_ID, device_auth=device_auth, sensor_status=sensor_status, device_status=device_status, print_data=print_data, print_recipe=print_recipe, device_alarm=device_alarm)
    
    timer=0
    while True:
        try:
            if timer > 60:
                if sensor_status != get_sensor_status():
                    sensor_status = get_sensor_status()
                    mqtt_client.publish({"target": "storage","action": "sensor-status","device":{"type": DEV_TYPE,"id": DEV_ID},"data":{"content": sensor_status}})
                timer=0
            
            if device_status != get_device_status():
                device_status = get_device_status()
                mqtt_client.publish({"target": "storage","action": "device-status","device":{"type": DEV_TYPE,"id": DEV_ID},"data":{"content": device_status}})
                
            if print_data != get_print_data():
                print_data = get_print_data()
                url = mqtt_client.get_presigned_url(method="put_object", key=DEV_TYPE+"/"+DEV_ID+"/pdata.json")
                mqtt_client.put_file_to_presigned_url(presigned_url=url, json_data=print_data)
                #mqtt_client.publish({"target": "storage","action": "print-data","device":{"type": DEV_TYPE,"id": DEV_ID},"data":{"content": print_data}})
            
            if print_recipe != get_print_recipe():
                print_recipe = get_print_recipe()
                mqtt_client.publish({"target": "storage","action": "print-recipe","device":{"type": DEV_TYPE,"id": DEV_ID},"data":{"content": print_recipe}})
                
            if device_alarm != get_device_alarm():
                device_alarm = get_device_alarm()
                mqtt_client.publish({"target": "storage","action": "device-alarm","device":{"type": DEV_TYPE,"id": DEV_ID},"data":{"content": device_alarm}})    
                device_alarm["alarm-list"].clear()
                with open("./static/alarm.json", 'w', encoding='utf-8') as file:
                    json.dump(device_alarm, file, indent=4, ensure_ascii=False)
                     
            time.sleep(1); timer += 1
        except KeyboardInterrupt:
            mqtt_client.disconnect()
            print("Program Exit")
            break
    