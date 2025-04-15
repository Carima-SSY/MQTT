#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "json.hpp"
#include "base64.h"
#include <chrono>
#include <ctime>

#include <sstream>  // stringstream을 위한 헤더

using json = nlohmann::json;

enum data_type {
	config = 0,
	sensor_status,
	device_status,
	print_data,
	print_recipe,
	device_alarm,
	request_data
};

class Dev_JSON{
private:
	std::string static_path;

	json sensor_status;
	json device_status;
	json print_data;
	json print_recipe;
	json device_alarm;
	json request_data;

	bool write_json(int type, json msg);
	json read_json(int type);

	std::vector<unsigned char> read_file_binary(const std::string& filepath);
	std::vector<std::string> split(const std::string& input, char delimiter);
public:
	Dev_JSON(std::string static_path);
	~Dev_JSON();

	bool set_sensor_status(double temp, double pres, double leve, double engl, double engr); // for dual engine like X1, DM400
	bool set_sensor_status(double temp, double pres, double leve, double engo); // for single engine like IMD, DM4K
	json get_sensor_status();
	bool send_sensor_status();

	bool set_device_status(bool allow_rmctrl, std::string status, std::string sel_data, std::string sel_recipe, std::string pdata, std::string precipe, int curr_layer, int total_layer, int remain_time, int progress);
	json get_device_status();
	bool send_device_status();

	bool reset_print_data();
	bool add_print_data(std::string file_name, std::string preview_path, int slice_resol_x, int slice_resol_y, double slice_thick, double slice_cnt, int file_size);
	json get_print_data();
	bool send_print_data();

	bool reset_print_recipe();
	bool add_print_recipe(std::string recipe); // for window 
	bool set_print_recipe(std::vector<std::string> recipe); // for raspberry pi
	json get_print_recipe();
	bool send_print_recipe();

	bool reset_device_alarm();
	bool add_device_alarm(std::string subject, std::string content);
	json get_device_alarm();
	json receive_device_alarm();
	bool send_device_alarm();

	bool reset_request_data();
	json get_request_data();
	json receive_request_data();
	bool send_request_data();
};