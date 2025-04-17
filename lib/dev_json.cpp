#include "dev_json.h"

std::vector<unsigned char> Dev_JSON::read_file_binary(const std::string& filepath) {
	std::ifstream file(filepath, std::ios::binary);
	if (!file) {
		throw std::runtime_error("Fail to open file: " + filepath);
	}

	file.seekg(0, std::ios::end);
	std::streamsize filesize = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<unsigned char> buffer(filesize);
	file.read(reinterpret_cast<char*>(buffer.data()), filesize);
	return buffer;
}

std::vector<std::string> Dev_JSON::split(const std::string& input, char delimiter) {
	std::vector<std::string> result;
	std::string temp;

	for (char ch : input) {
		if (ch == delimiter) {
			if (!temp.empty()) result.push_back(temp);
			temp.clear();
		}
		else {
			temp += ch;
		}
	}

	if (!temp.empty()) result.push_back(temp); // ������ ��ū �߰�
	return result;
}

bool Dev_JSON::write_json(int type, json msg) {
	std::string file_name;

	if (type == data_type::sensor_status) file_name = "sensor.json";
	else if (type == data_type::device_status) file_name = "dstatus.json";
	else if (type == data_type::print_data) file_name = "pdata.json";
	else if (type == data_type::print_recipe) file_name = "precipe.json";
	else if (type == data_type::device_alarm) file_name = "alarm.json";
	else if (type == data_type::request_data) file_name = "request.json";
	else return false;

	std::ofstream json_file(this->static_path + "\\" + file_name);
	json_file << msg.dump(4);
	json_file.close();

	return true;
}
json Dev_JSON::read_json(int type) {
	std::string file_name;

	if (type == data_type::request_data) file_name = "request.json";
	else if (type == data_type::device_alarm) file_name = "alarm.json";
	else return NULL;

	std::ifstream json_file(this->static_path + "\\" + file_name);
	json read_json;
	json_file >> read_json;
	json_file.close();

	return read_json;
}

Dev_JSON::Dev_JSON(std::string static_path) {
	this->static_path = static_path;
	printf("Create Dev_JSON Object\n");
}
Dev_JSON::~Dev_JSON() {
	printf("Delete Dev_JSON Object\n");
}

// for dual engine like X1, DM400
bool Dev_JSON::set_sensor_status(double temp, double pres, double leve, double engl, double engr) { 
	try {
		json sstatus;

		sstatus["temperture"] = temp;
		sstatus["pressure"] = pres;
		sstatus["waterlevel"] = leve;
		sstatus["engineled"] = { {"left", engl}, {"right", engr} };

		this->sensor_status = sstatus;
	}
	catch (...) {
		return false;
	}
	return true;
}
// for single engine like IMD, DM4K
bool Dev_JSON::set_sensor_status(double temp, double pres, double leve, double engo) { 
	try {
		json sstatus;

		sstatus["temperture"] = temp;
		sstatus["pressure"] = pres;
		sstatus["waterlevel"] = leve;
		sstatus["engineled"] = { {"left", engo} };

		this->sensor_status = sstatus;
	}
	catch (...) {
		return false;
	}
	return true;
}
json Dev_JSON::get_sensor_status() {
	return this->sensor_status;
}
bool Dev_JSON::send_sensor_status() {
	return this->write_json(data_type::sensor_status,this->sensor_status);
}

bool Dev_JSON::set_device_status(bool allow_rmctrl, std::string status, std::string sel_data, std::string sel_recipe, std::string pdata, std::string precipe, int curr_layer, int total_layer, int remain_time, int progress) {
	try {
		json dstatus;

		dstatus["allow-remote-control"] = (int)allow_rmctrl;
		dstatus["status"] = status;
		dstatus["selected"] = { {"data", sel_data}, {"recipe",sel_recipe} };
		dstatus["printting"] = { {"data", pdata}, {"recipe",precipe},{"current-layer", curr_layer}, {"total-layer", total_layer}, {"remaining-time", remain_time}, {"printing-progress",progress} };

		this->device_status = dstatus;
	}
	catch (...) {
		return false;
	}
	return true;
}

json Dev_JSON::get_device_status() {
	return this->device_status;
}
bool Dev_JSON::send_device_status() {
	return this->write_json(data_type::device_status, this->device_status);
}

bool Dev_JSON::reset_print_data() {
	try {
		this->print_data.clear();
	}
	catch (...) {
		return false;
	}
	return true;
}
bool Dev_JSON::add_print_data(std::string file_name, std::string preview_path, int slice_resol_x, int slice_resol_y, double slice_thick, double slice_cnt, int file_size) {
	try {
		json file_info;

		json preview;
		std::vector<std::string> split_str = split(preview_path, '\\');
		preview["name"] = split_str[split_str.size() - 1];

		std::vector<unsigned char> preview_data = read_file_binary(preview_path.c_str());
		std::string encoded_preview = base64_encode(preview_data.data(), preview_data.size());
		preview["content"] = encoded_preview;

		file_info["preview"] = preview;

		json slice_img;
		slice_img["resol_x"] = slice_resol_x;
		slice_img["resol_y"] = slice_resol_y;
		slice_img["thick"] = slice_thick;
		slice_img["count"] = slice_cnt;
		file_info["slice-img"] = slice_img;

		json fsize;
		fsize["size"] = file_size;
		file_info["file"] = fsize;

		this->print_data[file_name] = file_info;
	}
	catch (...) {
		return false;
	}
	return true;
}
json Dev_JSON::get_print_data() {
	return this->print_data;
}
bool Dev_JSON::send_print_data() {
	return this->write_json(data_type::print_data, this->print_data);
}

bool Dev_JSON::reset_print_recipe() {
	try {
		this->print_recipe.clear();
	}
	catch (...) {
		return false;
	}
	return true;
}
// for window 
bool Dev_JSON::add_print_recipe(std::string recipe_path) {
	try {
		std::vector<std::string> split_str = split(recipe_path, '\\');
		std::string name = split_str[split_str.size() - 1];

		std::vector<unsigned char> recipe_data = read_file_binary(recipe_path.c_str());
		std::string encoded_recipe = base64_encode(recipe_data.data(), recipe_data.size());

		this->print_recipe[name] = { {"content", encoded_recipe} };
	}
	catch (...) {
		return false;
	}
	return true;
}
// for raspberry pi
bool Dev_JSON::set_print_recipe(std::vector<std::string> recipe) {
	try {
		json precipe;
		json recipe_list = json::array();

		for (int i = 0; i < recipe.size(); i++) recipe_list.push_back(recipe[i]);
		
		precipe["recipe-list"] = recipe_list;
		this->print_recipe = precipe;
	}
	catch (...) {
		return false;
	}
	return true;
}
json Dev_JSON::get_print_recipe() {
	return this->print_recipe;
}
bool Dev_JSON::send_print_recipe(){
	return this->write_json(data_type::print_recipe, this->print_recipe);
}

bool Dev_JSON::reset_device_alarm() {
	try {
		this->device_alarm.clear();
		this->device_alarm["alarm-list"] = json::array();
		
	}
	catch (...) {
		return false;
	}

	return true;
}
bool Dev_JSON::add_device_alarm(std::string subject, std::string content) {
	try {
		json alarm;
		alarm["subject"] = subject;
		alarm["content"] = content;

		auto now = std::chrono::system_clock::now();
		std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
		std::tm* local_tm = std::localtime(&now_time_t);
		std::ostringstream oss;
		oss << std::put_time(local_tm, "%Y:%m:%d:%H:%M:%S");

		alarm["created_date"] = oss.str();

		this->device_alarm["alarm-list"].push_back(alarm);
	}
	catch (...) {
		return false;
	}
	return true;
}
json Dev_JSON::get_device_alarm() {
	return this->device_alarm;
}
json Dev_JSON::receive_device_alarm() {
	return this->device_alarm = this->read_json(data_type::device_alarm);
}
bool Dev_JSON::send_device_alarm() {
	return this->write_json(data_type::device_alarm, this->device_alarm);
}

bool Dev_JSON::reset_request_data() {
	try {
		this->request_data.clear();
	}
	catch (...) {
		return false;
	}

	return true;
}
json Dev_JSON::get_request_data(){
	return this->request_data;
}
json Dev_JSON::receive_request_data() {
	return this->request_data = this->read_json(data_type::request_data);
}
bool Dev_JSON::send_request_data() {
	return this->write_json(data_type::request_data, this->request_data);
}