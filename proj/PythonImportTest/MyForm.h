#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "dev_json.h"
#include "pr_state.h"

using json = nlohmann::json;

namespace PythonImportTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;         // 디렉터리 및 파일 관련 기능
	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

		Dev_JSON* dev_json;
		Process_State^ pr_state;
		char* _staticpath = "C:\\Users\\carima1301\\Documents\\WebProgramming\\MQTT\\ver2\\static";

	private: System::Windows::Forms::Button^ bt_sensor_status;
	private: System::Windows::Forms::Button^ bt_device_status;
	private: System::Windows::Forms::Button^ bt_device_alarm;
	private: System::Windows::Forms::Button^ bt_request_data;
	private: System::Windows::Forms::Button^ bt_print_recipe;
	private: System::Windows::Forms::Button^ bt_print_data;
	private: System::Windows::Forms::Button^ bt_kill_process;
	private: System::Windows::Forms::Button^ bt_check_process;
	private: System::Windows::Forms::Button^ bt_init_process;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bt_sensor_status = (gcnew System::Windows::Forms::Button());
			this->bt_device_status = (gcnew System::Windows::Forms::Button());
			this->bt_device_alarm = (gcnew System::Windows::Forms::Button());
			this->bt_request_data = (gcnew System::Windows::Forms::Button());
			this->bt_print_recipe = (gcnew System::Windows::Forms::Button());
			this->bt_print_data = (gcnew System::Windows::Forms::Button());
			this->bt_kill_process = (gcnew System::Windows::Forms::Button());
			this->bt_check_process = (gcnew System::Windows::Forms::Button());
			this->bt_init_process = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// bt_sensor_status
			// 
			this->bt_sensor_status->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_sensor_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_sensor_status->Location = System::Drawing::Point(12, 21);
			this->bt_sensor_status->Name = L"bt_sensor_status";
			this->bt_sensor_status->Size = System::Drawing::Size(203, 84);
			this->bt_sensor_status->TabIndex = 0;
			this->bt_sensor_status->Text = L"sensor_status";
			this->bt_sensor_status->UseVisualStyleBackColor = false;
			this->bt_sensor_status->Click += gcnew System::EventHandler(this, &MyForm::bt_sensor_status_Click);
			// 
			// bt_device_status
			// 
			this->bt_device_status->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_device_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_device_status->Location = System::Drawing::Point(240, 21);
			this->bt_device_status->Name = L"bt_device_status";
			this->bt_device_status->Size = System::Drawing::Size(203, 84);
			this->bt_device_status->TabIndex = 1;
			this->bt_device_status->Text = L"device_status";
			this->bt_device_status->UseVisualStyleBackColor = false;
			this->bt_device_status->Click += gcnew System::EventHandler(this, &MyForm::bt_device_status_Click);
			// 
			// bt_device_alarm
			// 
			this->bt_device_alarm->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_device_alarm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_device_alarm->Location = System::Drawing::Point(471, 21);
			this->bt_device_alarm->Name = L"bt_device_alarm";
			this->bt_device_alarm->Size = System::Drawing::Size(203, 84);
			this->bt_device_alarm->TabIndex = 2;
			this->bt_device_alarm->Text = L"device_alarm";
			this->bt_device_alarm->UseVisualStyleBackColor = false;
			this->bt_device_alarm->Click += gcnew System::EventHandler(this, &MyForm::bt_device_alarm_Click);
			// 
			// bt_request_data
			// 
			this->bt_request_data->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_request_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_request_data->Location = System::Drawing::Point(471, 135);
			this->bt_request_data->Name = L"bt_request_data";
			this->bt_request_data->Size = System::Drawing::Size(203, 84);
			this->bt_request_data->TabIndex = 5;
			this->bt_request_data->Text = L"request_data";
			this->bt_request_data->UseVisualStyleBackColor = false;
			this->bt_request_data->Click += gcnew System::EventHandler(this, &MyForm::bt_request_data_Click);
			// 
			// bt_print_recipe
			// 
			this->bt_print_recipe->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_print_recipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_print_recipe->Location = System::Drawing::Point(240, 135);
			this->bt_print_recipe->Name = L"bt_print_recipe";
			this->bt_print_recipe->Size = System::Drawing::Size(203, 84);
			this->bt_print_recipe->TabIndex = 4;
			this->bt_print_recipe->Text = L"print_recipe";
			this->bt_print_recipe->UseVisualStyleBackColor = false;
			this->bt_print_recipe->Click += gcnew System::EventHandler(this, &MyForm::bt_print_recipe_Click);
			// 
			// bt_print_data
			// 
			this->bt_print_data->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_print_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_print_data->Location = System::Drawing::Point(12, 135);
			this->bt_print_data->Name = L"bt_print_data";
			this->bt_print_data->Size = System::Drawing::Size(203, 84);
			this->bt_print_data->TabIndex = 3;
			this->bt_print_data->Text = L"print_data";
			this->bt_print_data->UseVisualStyleBackColor = false;
			this->bt_print_data->Click += gcnew System::EventHandler(this, &MyForm::bt_print_data_Click);
			// 
			// bt_kill_process
			// 
			this->bt_kill_process->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_kill_process->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_kill_process->Location = System::Drawing::Point(471, 255);
			this->bt_kill_process->Name = L"bt_kill_process";
			this->bt_kill_process->Size = System::Drawing::Size(203, 84);
			this->bt_kill_process->TabIndex = 8;
			this->bt_kill_process->Text = L"kill_process";
			this->bt_kill_process->UseVisualStyleBackColor = false;
			this->bt_kill_process->Click += gcnew System::EventHandler(this, &MyForm::bt_kill_process_Click);
			// 
			// bt_check_process
			// 
			this->bt_check_process->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_check_process->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_check_process->Location = System::Drawing::Point(240, 255);
			this->bt_check_process->Name = L"bt_check_process";
			this->bt_check_process->Size = System::Drawing::Size(203, 84);
			this->bt_check_process->TabIndex = 7;
			this->bt_check_process->Text = L"check_process";
			this->bt_check_process->UseVisualStyleBackColor = false;
			this->bt_check_process->Click += gcnew System::EventHandler(this, &MyForm::bt_check_process_Click);
			// 
			// bt_init_process
			// 
			this->bt_init_process->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_init_process->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_init_process->Location = System::Drawing::Point(12, 255);
			this->bt_init_process->Name = L"bt_init_process";
			this->bt_init_process->Size = System::Drawing::Size(203, 84);
			this->bt_init_process->TabIndex = 6;
			this->bt_init_process->Text = L"init_process";
			this->bt_init_process->UseVisualStyleBackColor = false;
			this->bt_init_process->Click += gcnew System::EventHandler(this, &MyForm::bt_init_process_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(690, 367);
			this->Controls->Add(this->bt_kill_process);
			this->Controls->Add(this->bt_check_process);
			this->Controls->Add(this->bt_init_process);
			this->Controls->Add(this->bt_request_data);
			this->Controls->Add(this->bt_print_recipe);
			this->Controls->Add(this->bt_print_data);
			this->Controls->Add(this->bt_device_alarm);
			this->Controls->Add(this->bt_device_status);
			this->Controls->Add(this->bt_sensor_status);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e){
		dev_json = new Dev_JSON(_staticpath);
		pr_state = gcnew Process_State("C:\\Users\\carima1301\\Documents\\WebProgramming\\MQTT\\ver2\\MqttApp.exe");
	}
	private: System::Void bt_sensor_status_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->set_sensor_status(25, 25, 25, 25, 25);
		std::cout << this->dev_json->get_sensor_status() << "\n";
		this->dev_json->send_sensor_status();
	}
	private: System::Void bt_device_status_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->set_device_status(false, "IDLE", "test.slice", "test.xml", "-", "-", 0, 0, 0, 0);
		std::cout << this->dev_json->get_device_status() << "\n";
		this->dev_json->send_device_status();
	}
	private: System::Void bt_print_data_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->add_print_data("Carima X1_100um.slice", "C:\\X1_Carima\\Datas\\Carima X1_100um.slice\\Preview_t.png", 4240, 3840, 0.1, 1555, 133690317);
		std::cout << this->dev_json->get_print_data() << "\n";
		this->dev_json->send_print_data();
	}
	private: System::Void bt_print_recipe_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->add_print_recipe("C:\\X1_Carima\\Recipes\\CARIMA_TEST.xml");
		this->dev_json->add_print_recipe("C:\\X1_Carima\\Recipes\\TestRecipe.xml");
		this->dev_json->add_print_recipe("C:\\X1_Carima\\Recipes\\TestRecipe_Copy.xml");

		std::cout << this->dev_json->get_print_recipe() << "\n";
		this->dev_json->send_print_recipe();
	}
	private: System::Void bt_device_alarm_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->receive_device_alarm();

		this->dev_json->add_device_alarm("test4", "hello mqtt");
		this->dev_json->add_device_alarm("test5", "hello mqtt");
		this->dev_json->add_device_alarm("test6", "hello mqtt");

		std::cout << this->dev_json->get_device_alarm() << "\n";
		this->dev_json->send_device_alarm();
	}
	private: System::Void bt_request_data_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dev_json->receive_request_data();
		std::cout << this->dev_json->get_request_data() << "\n";
	}
	private: System::Void bt_init_process_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pr_state->initProcess();
	}
	private: System::Void bt_check_process_Click(System::Object^ sender, System::EventArgs^ e) {
		std::cout << (int)this->pr_state->checkStatus() << "\n";
	}
	private: System::Void bt_kill_process_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pr_state->killProcess();
	}
};
}
