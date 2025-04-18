#pragma once
#include <iostream>
#include <stdio.h>
#include <msclr/marshal_cppstd.h>
#include <windows.h>
#include "dev_json.h"
#include "pr_state.h"

using json = nlohmann::json;
public enum STATUS{
	OFFLINE = 0,
	IDLE,
	PRINTING,
	PRINTING_PAUSE,
	PRINTING_ABORT,
	PRINTING_FINISH
};
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
		String^ print_data_path = "C:\\X1_Carima\\Datas";
		String^ print_recipe_path = "C:\\X1_Carima\\Recipes";

		int printstatus = STATUS::IDLE;




	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tb_engr;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tb_engl;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tb_leve;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tb_temp;
	private: System::ComponentModel::BackgroundWorker^ bg_sensor_status;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ tb_totalay;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ tb_currlay;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ tb_prrecipe;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ tb_prdata;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tb_selrecipe;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ tb_seldata;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ tb_status;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ tb_allow_rmctrl;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ tb_prog;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ tb_retime;

	private: System::Windows::Forms::ListBox^ lb_printdata;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ bt_reset_datadir;
	private: System::Windows::Forms::Button^ bt_reset_recipedir;

	private: System::ComponentModel::BackgroundWorker^ bg_reset_printdata;
	private: System::ComponentModel::BackgroundWorker^ bg_reset_printrecipe;
	private: System::Windows::Forms::Button^ bt_print_abort;
	private: System::Windows::Forms::Button^ bt_print_pause;
	private: System::Windows::Forms::Button^ bt_print_start;
	private: System::ComponentModel::BackgroundWorker^ bg_printcontrol;
	private: System::Windows::Forms::Button^ bt_allow_ctrl_change;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::ComponentModel::BackgroundWorker^ bg_device_status;
	private: System::ComponentModel::BackgroundWorker^ bg_print_data;
	private: System::ComponentModel::BackgroundWorker^ bg_print_recipe;
	private: System::ComponentModel::BackgroundWorker^ bg_request_data;
private: System::Windows::Forms::Button^ bt_start_mqtt;
private: System::ComponentModel::BackgroundWorker^ bg_process_status;

	private: System::Windows::Forms::ListBox^ lb_printrecipe;







#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_engr = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tb_engl = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_leve = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb_temp = (gcnew System::Windows::Forms::TextBox());
			this->bg_sensor_status = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tb_prog = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tb_retime = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tb_totalay = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tb_currlay = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tb_prrecipe = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tb_prdata = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tb_selrecipe = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tb_seldata = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb_status = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tb_allow_rmctrl = (gcnew System::Windows::Forms::TextBox());
			this->lb_printdata = (gcnew System::Windows::Forms::ListBox());
			this->lb_printrecipe = (gcnew System::Windows::Forms::ListBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->bt_allow_ctrl_change = (gcnew System::Windows::Forms::Button());
			this->bt_print_abort = (gcnew System::Windows::Forms::Button());
			this->bt_print_pause = (gcnew System::Windows::Forms::Button());
			this->bt_print_start = (gcnew System::Windows::Forms::Button());
			this->bt_reset_recipedir = (gcnew System::Windows::Forms::Button());
			this->bt_reset_datadir = (gcnew System::Windows::Forms::Button());
			this->bg_reset_printdata = (gcnew System::ComponentModel::BackgroundWorker());
			this->bg_reset_printrecipe = (gcnew System::ComponentModel::BackgroundWorker());
			this->bg_printcontrol = (gcnew System::ComponentModel::BackgroundWorker());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->bg_device_status = (gcnew System::ComponentModel::BackgroundWorker());
			this->bg_print_data = (gcnew System::ComponentModel::BackgroundWorker());
			this->bg_print_recipe = (gcnew System::ComponentModel::BackgroundWorker());
			this->bg_request_data = (gcnew System::ComponentModel::BackgroundWorker());
			this->bt_start_mqtt = (gcnew System::Windows::Forms::Button());
			this->bg_process_status = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->tb_engr);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->tb_engl);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->tb_leve);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->tb_temp);
			this->panel1->Location = System::Drawing::Point(364, 93);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(293, 229);
			this->panel1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(26, 174);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(148, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Engine-Right";
			// 
			// tb_engr
			// 
			this->tb_engr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_engr->Location = System::Drawing::Point(182, 171);
			this->tb_engr->Name = L"tb_engr";
			this->tb_engr->Size = System::Drawing::Size(90, 31);
			this->tb_engr->TabIndex = 6;
			this->tb_engr->Text = L"0";
			this->tb_engr->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(26, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 25);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Engine-Left";
			// 
			// tb_engl
			// 
			this->tb_engl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_engl->Location = System::Drawing::Point(182, 123);
			this->tb_engl->Name = L"tb_engl";
			this->tb_engl->Size = System::Drawing::Size(90, 31);
			this->tb_engl->TabIndex = 4;
			this->tb_engl->Text = L"0";
			this->tb_engl->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label2->Location = System::Drawing::Point(26, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Waterlevel";
			// 
			// tb_leve
			// 
			this->tb_leve->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_leve->Location = System::Drawing::Point(182, 76);
			this->tb_leve->Name = L"tb_leve";
			this->tb_leve->Size = System::Drawing::Size(90, 31);
			this->tb_leve->TabIndex = 2;
			this->tb_leve->Text = L"0";
			this->tb_leve->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(26, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Temperature";
			// 
			// tb_temp
			// 
			this->tb_temp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_temp->Location = System::Drawing::Point(182, 31);
			this->tb_temp->Name = L"tb_temp";
			this->tb_temp->Size = System::Drawing::Size(90, 31);
			this->tb_temp->TabIndex = 0;
			this->tb_temp->Text = L"0";
			this->tb_temp->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// bg_sensor_status
			// 
			this->bg_sensor_status->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_sensor_status_DoWork);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->tb_prog);
			this->panel2->Controls->Add(this->label14);
			this->panel2->Controls->Add(this->tb_retime);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->tb_totalay);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->tb_currlay);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->tb_prrecipe);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->tb_prdata);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->tb_selrecipe);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->tb_seldata);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->tb_status);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->tb_allow_rmctrl);
			this->panel2->Location = System::Drawing::Point(364, 358);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1389, 220);
			this->panel2->TabIndex = 8;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label13->Location = System::Drawing::Point(940, 75);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(194, 25);
			this->label13->TabIndex = 19;
			this->label13->Text = L"Printing Progress";
			// 
			// tb_prog
			// 
			this->tb_prog->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_prog->Location = System::Drawing::Point(1144, 72);
			this->tb_prog->Name = L"tb_prog";
			this->tb_prog->Size = System::Drawing::Size(220, 31);
			this->tb_prog->TabIndex = 18;
			this->tb_prog->Text = L"0";
			this->tb_prog->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label14->Location = System::Drawing::Point(940, 30);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(181, 25);
			this->label14->TabIndex = 17;
			this->label14->Text = L"Remaining Time";
			// 
			// tb_retime
			// 
			this->tb_retime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_retime->Location = System::Drawing::Point(1144, 27);
			this->tb_retime->Name = L"tb_retime";
			this->tb_retime->Size = System::Drawing::Size(220, 31);
			this->tb_retime->TabIndex = 16;
			this->tb_retime->Text = L"0";
			this->tb_retime->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(495, 170);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(131, 25);
			this->label9->TabIndex = 15;
			this->label9->Text = L"Total Layer";
			// 
			// tb_totalay
			// 
			this->tb_totalay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_totalay->Location = System::Drawing::Point(689, 167);
			this->tb_totalay->Name = L"tb_totalay";
			this->tb_totalay->Size = System::Drawing::Size(220, 31);
			this->tb_totalay->TabIndex = 14;
			this->tb_totalay->Text = L"0";
			this->tb_totalay->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label10->Location = System::Drawing::Point(495, 122);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(156, 25);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Current Layer";
			// 
			// tb_currlay
			// 
			this->tb_currlay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_currlay->Location = System::Drawing::Point(689, 119);
			this->tb_currlay->Name = L"tb_currlay";
			this->tb_currlay->Size = System::Drawing::Size(220, 31);
			this->tb_currlay->TabIndex = 12;
			this->tb_currlay->Text = L"0";
			this->tb_currlay->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label11->Location = System::Drawing::Point(495, 75);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(173, 25);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Printing Recipe";
			// 
			// tb_prrecipe
			// 
			this->tb_prrecipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_prrecipe->Location = System::Drawing::Point(689, 69);
			this->tb_prrecipe->Name = L"tb_prrecipe";
			this->tb_prrecipe->Size = System::Drawing::Size(220, 31);
			this->tb_prrecipe->TabIndex = 10;
			this->tb_prrecipe->Text = L"-";
			this->tb_prrecipe->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label12->Location = System::Drawing::Point(495, 30);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(149, 25);
			this->label12->TabIndex = 9;
			this->label12->Text = L"Printing Data";
			// 
			// tb_prdata
			// 
			this->tb_prdata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_prdata->Location = System::Drawing::Point(689, 27);
			this->tb_prdata->Name = L"tb_prdata";
			this->tb_prdata->Size = System::Drawing::Size(220, 31);
			this->tb_prdata->TabIndex = 8;
			this->tb_prdata->Text = L"-";
			this->tb_prdata->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(26, 170);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(184, 25);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Selected Recipe";
			// 
			// tb_selrecipe
			// 
			this->tb_selrecipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_selrecipe->Location = System::Drawing::Point(230, 167);
			this->tb_selrecipe->Name = L"tb_selrecipe";
			this->tb_selrecipe->Size = System::Drawing::Size(220, 31);
			this->tb_selrecipe->TabIndex = 6;
			this->tb_selrecipe->Text = L"-";
			this->tb_selrecipe->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(26, 122);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(160, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Selected Data";
			// 
			// tb_seldata
			// 
			this->tb_seldata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_seldata->Location = System::Drawing::Point(230, 119);
			this->tb_seldata->Name = L"tb_seldata";
			this->tb_seldata->Size = System::Drawing::Size(220, 31);
			this->tb_seldata->TabIndex = 4;
			this->tb_seldata->Text = L"-";
			this->tb_seldata->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(26, 75);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(79, 25);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Status";
			// 
			// tb_status
			// 
			this->tb_status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_status->Location = System::Drawing::Point(230, 72);
			this->tb_status->Name = L"tb_status";
			this->tb_status->Size = System::Drawing::Size(220, 31);
			this->tb_status->TabIndex = 2;
			this->tb_status->Text = L"IDLE";
			this->tb_status->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->label8->Location = System::Drawing::Point(26, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(178, 25);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Allow to Control";
			// 
			// tb_allow_rmctrl
			// 
			this->tb_allow_rmctrl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->tb_allow_rmctrl->Location = System::Drawing::Point(230, 27);
			this->tb_allow_rmctrl->Name = L"tb_allow_rmctrl";
			this->tb_allow_rmctrl->Size = System::Drawing::Size(220, 31);
			this->tb_allow_rmctrl->TabIndex = 0;
			this->tb_allow_rmctrl->Text = L"0";
			this->tb_allow_rmctrl->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lb_printdata
			// 
			this->lb_printdata->BackColor = System::Drawing::SystemColors::Menu;
			this->lb_printdata->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->lb_printdata->FormattingEnabled = true;
			this->lb_printdata->ItemHeight = 25;
			this->lb_printdata->Location = System::Drawing::Point(704, 93);
			this->lb_printdata->Name = L"lb_printdata";
			this->lb_printdata->Size = System::Drawing::Size(500, 229);
			this->lb_printdata->TabIndex = 9;
			this->lb_printdata->Click += gcnew System::EventHandler(this, &MyForm::lb_printdata_Click);
			// 
			// lb_printrecipe
			// 
			this->lb_printrecipe->BackColor = System::Drawing::SystemColors::Menu;
			this->lb_printrecipe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->lb_printrecipe->FormattingEnabled = true;
			this->lb_printrecipe->ItemHeight = 25;
			this->lb_printrecipe->Location = System::Drawing::Point(1253, 93);
			this->lb_printrecipe->Name = L"lb_printrecipe";
			this->lb_printrecipe->Size = System::Drawing::Size(500, 229);
			this->lb_printrecipe->TabIndex = 10;
			this->lb_printrecipe->Click += gcnew System::EventHandler(this, &MyForm::lb_printrecipe_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label15);
			this->panel3->Controls->Add(this->bt_allow_ctrl_change);
			this->panel3->Controls->Add(this->bt_print_abort);
			this->panel3->Controls->Add(this->bt_print_pause);
			this->panel3->Controls->Add(this->bt_print_start);
			this->panel3->Controls->Add(this->bt_reset_recipedir);
			this->panel3->Controls->Add(this->bt_reset_datadir);
			this->panel3->Location = System::Drawing::Point(40, 93);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(282, 485);
			this->panel3->TabIndex = 8;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(38, 23);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(204, 33);
			this->label15->TabIndex = 6;
			this->label15->Text = L"Control Panel";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bt_allow_ctrl_change
			// 
			this->bt_allow_ctrl_change->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_allow_ctrl_change->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_allow_ctrl_change->Location = System::Drawing::Point(29, 79);
			this->bt_allow_ctrl_change->Name = L"bt_allow_ctrl_change";
			this->bt_allow_ctrl_change->Size = System::Drawing::Size(225, 45);
			this->bt_allow_ctrl_change->TabIndex = 5;
			this->bt_allow_ctrl_change->Text = L"allow_ctrl_change";
			this->bt_allow_ctrl_change->UseVisualStyleBackColor = false;
			// 
			// bt_print_abort
			// 
			this->bt_print_abort->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_print_abort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_print_abort->Location = System::Drawing::Point(29, 415);
			this->bt_print_abort->Name = L"bt_print_abort";
			this->bt_print_abort->Size = System::Drawing::Size(225, 45);
			this->bt_print_abort->TabIndex = 4;
			this->bt_print_abort->Text = L"printing_abort";
			this->bt_print_abort->UseVisualStyleBackColor = false;
			this->bt_print_abort->Click += gcnew System::EventHandler(this, &MyForm::bt_print_abort_Click);
			// 
			// bt_print_pause
			// 
			this->bt_print_pause->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_print_pause->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_print_pause->Location = System::Drawing::Point(29, 346);
			this->bt_print_pause->Name = L"bt_print_pause";
			this->bt_print_pause->Size = System::Drawing::Size(225, 45);
			this->bt_print_pause->TabIndex = 3;
			this->bt_print_pause->Text = L"printing_pause";
			this->bt_print_pause->UseVisualStyleBackColor = false;
			this->bt_print_pause->Click += gcnew System::EventHandler(this, &MyForm::bt_print_pause_Click);
			// 
			// bt_print_start
			// 
			this->bt_print_start->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_print_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_print_start->Location = System::Drawing::Point(29, 276);
			this->bt_print_start->Name = L"bt_print_start";
			this->bt_print_start->Size = System::Drawing::Size(225, 45);
			this->bt_print_start->TabIndex = 2;
			this->bt_print_start->Text = L"printing_start";
			this->bt_print_start->UseVisualStyleBackColor = false;
			this->bt_print_start->Click += gcnew System::EventHandler(this, &MyForm::bt_print_start_Click);
			// 
			// bt_reset_recipedir
			// 
			this->bt_reset_recipedir->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_reset_recipedir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_reset_recipedir->Location = System::Drawing::Point(29, 208);
			this->bt_reset_recipedir->Name = L"bt_reset_recipedir";
			this->bt_reset_recipedir->Size = System::Drawing::Size(225, 45);
			this->bt_reset_recipedir->TabIndex = 1;
			this->bt_reset_recipedir->Text = L"reset_print_recipe";
			this->bt_reset_recipedir->UseVisualStyleBackColor = false;
			this->bt_reset_recipedir->Click += gcnew System::EventHandler(this, &MyForm::bt_reset_recipedir_Click);
			// 
			// bt_reset_datadir
			// 
			this->bt_reset_datadir->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_reset_datadir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_reset_datadir->Location = System::Drawing::Point(29, 143);
			this->bt_reset_datadir->Name = L"bt_reset_datadir";
			this->bt_reset_datadir->Size = System::Drawing::Size(225, 45);
			this->bt_reset_datadir->TabIndex = 0;
			this->bt_reset_datadir->Text = L"reset_print_data";
			this->bt_reset_datadir->UseVisualStyleBackColor = false;
			this->bt_reset_datadir->Click += gcnew System::EventHandler(this, &MyForm::bt_reset_datadir_Click);
			// 
			// bg_reset_printdata
			// 
			this->bg_reset_printdata->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_reset_printdata_DoWork);
			// 
			// bg_reset_printrecipe
			// 
			this->bg_reset_printrecipe->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_reset_printrecipe_DoWork);
			// 
			// bg_printcontrol
			// 
			this->bg_printcontrol->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_printcontrol_DoWork);
			this->bg_printcontrol->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::bg_printcontrol_RunWorkerCompleted);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"HY견고딕", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(33, 23);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(836, 37);
			this->label16->TabIndex = 7;
			this->label16->Text = L"D e v i c e  A p p  S i m u l a t i o n  T e s t";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// bg_device_status
			// 
			this->bg_device_status->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_device_status_DoWork);
			// 
			// bg_print_data
			// 
			this->bg_print_data->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_print_data_DoWork);
			// 
			// bg_print_recipe
			// 
			this->bg_print_recipe->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_print_recipe_DoWork);
			// 
			// bg_request_data
			// 
			this->bg_request_data->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_request_data_DoWork);
			// 
			// bt_start_mqtt
			// 
			this->bt_start_mqtt->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->bt_start_mqtt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold));
			this->bt_start_mqtt->Location = System::Drawing::Point(1528, 25);
			this->bt_start_mqtt->Name = L"bt_start_mqtt";
			this->bt_start_mqtt->Size = System::Drawing::Size(225, 45);
			this->bt_start_mqtt->TabIndex = 7;
			this->bt_start_mqtt->Text = L"Start MQTT App";
			this->bt_start_mqtt->UseVisualStyleBackColor = false;
			this->bt_start_mqtt->Click += gcnew System::EventHandler(this, &MyForm::bt_start_mqtt_Click);
			// 
			// bg_process_status
			// 
			this->bg_process_status->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::bg_process_status_DoWork);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(1799, 611);
			this->Controls->Add(this->bt_start_mqtt);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->lb_printrecipe);
			this->Controls->Add(this->lb_printdata);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e){
		dev_json = new Dev_JSON(_staticpath);
		pr_state = gcnew Process_State("C:\\Users\\carima1301\\Documents\\WebProgramming\\MQTT\\ver2","MqttApp.exe");

		bg_sensor_status->RunWorkerAsync();
		bg_device_status->RunWorkerAsync();

		bg_reset_printdata->RunWorkerAsync();
		bg_reset_printrecipe->RunWorkerAsync();
	
		bg_print_data->RunWorkerAsync();
		bg_print_recipe->RunWorkerAsync();
	}

	private: System::Void bg_sensor_status_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		Random^ rnd= gcnew Random();

		while (true) {
			this->tb_temp->Text = (rnd->NextDouble() * 15).ToString("F2");
			this->tb_leve->Text = (rnd->NextDouble() * 3).ToString("F2");
			this->tb_engl->Text = (rnd->NextDouble() * 21).ToString("F2");
			this->tb_engr->Text = (rnd->NextDouble() * 23).ToString("F2");
			
			this->dev_json->set_sensor_status(
				Convert::ToDouble(this->tb_temp->Text),
				0,
				Convert::ToDouble(this->tb_leve->Text),
				Convert::ToDouble(this->tb_engl->Text),
				Convert::ToDouble(this->tb_engr->Text)
			);

			this->dev_json->send_sensor_status();
			Sleep(5000);
		}
	}
	private: System::Void bg_device_status_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (true) {
			this->dev_json->set_device_status(
				Convert::ToInt32(this->tb_allow_rmctrl->Text),
				msclr::interop::marshal_as<std::string>(this->tb_status->Text),
				msclr::interop::marshal_as<std::string>(this->tb_seldata->Text),
				msclr::interop::marshal_as<std::string>(this->tb_selrecipe->Text),
				msclr::interop::marshal_as<std::string>(this->tb_prdata->Text),
				msclr::interop::marshal_as<std::string>(this->tb_prrecipe->Text),
				Convert::ToInt32(this->tb_currlay->Text),
				Convert::ToInt32(this->tb_totalay->Text),
				Convert::ToInt32(this->tb_retime->Text),
				Convert::ToInt32(this->tb_prog->Text)
			);

			//std::cout << "Device Status:\n\t" << this->dev_json->get_device_status() << "\n\n";
			this->dev_json->send_device_status();
			Sleep(10000);
		}
	}
	private: System::Void bg_print_data_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (true) {
			this->dev_json->reset_print_data();
			
			for (int i = 0; i < this->lb_printdata->Items->Count; i++) {
				String^ pdata = this->print_data_path + "\\" + this->lb_printdata->Items[i]->ToString();

				cli::array<String^>^ pdata_filelist = Directory::GetFiles(pdata);
				String^ preview_path;
				for (int j = 0; j < pdata_filelist->Length; j++) {
					if (pdata_filelist[j]->Contains("Preview")) {
						preview_path = pdata_filelist[j];
						break;
					}
				}

				this->dev_json->add_print_data(
					msclr::interop::marshal_as<std::string>(this->lb_printdata->Items[i]->ToString()),
					msclr::interop::marshal_as<std::string>(preview_path),
					4240,3840,0.1,1000,46545232
				);
			}

			//std::cout << "Print Data:\n\t" << this->dev_json->get_print_data() << "\n\n";
			this->dev_json->send_print_data();
			Sleep(10000);
		}
	}
	private: System::Void bg_print_recipe_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (true) {
			for (int i = 0; i < this->lb_printrecipe->Items->Count; i++) {
				this->dev_json->add_print_recipe(msclr::interop::marshal_as<std::string>(this->print_recipe_path + "\\" + this->lb_printrecipe->Items[i]->ToString()));
			}

			//std::cout << "Print Recipe:\n\t" << this->dev_json->get_print_recipe() << "\n\n";
			this->dev_json->send_print_recipe();
			Sleep(10000);
		}

	}
	private: System::Void bg_request_data_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (true) {
			this->dev_json->receive_request_data();
			std::cout << this->dev_json->get_request_data() << "\n";

			Sleep(5000);
		}
	}
	private: System::Void bg_reset_printdata_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		this->lb_printdata->Items->Clear();

		cli::array<String^>^print_data_list = Directory::GetDirectories(this->print_data_path);

		for (int i = 0; i < print_data_list->Length; i++) {
			if (print_data_list[i]->Contains(".slice") || print_data_list[i]->Contains(".crmaslice")) {
				cli::array<String^>^ path_list = print_data_list[i]->Split('\\');
				this->lb_printdata->Items->Add(path_list[path_list->Length - 1]);
			}
		}
	}
	private: System::Void bt_reset_datadir_Click(System::Object^ sender, System::EventArgs^ e) {
		bg_reset_printdata->RunWorkerAsync();
		this->tb_seldata->Text = "-";
	}
	private: System::Void lb_printdata_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lb_printdata->SelectedItems->Count > 0) {
			this->tb_seldata->Text = this->lb_printdata->SelectedItems[0]->ToString();
		}
	}

	private: System::Void bg_reset_printrecipe_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		this->lb_printrecipe->Items->Clear();

		cli::array<String^>^ print_recipe_list = Directory::GetFiles(this->print_recipe_path);

		for (int i = 0; i < print_recipe_list->Length; i++) {
			if (print_recipe_list[i]->Contains(".xml")) {
				cli::array<String^>^ path_list = print_recipe_list[i]->Split('\\');
				this->lb_printrecipe->Items->Add(path_list[path_list->Length - 1]);
			}
		}
	}
	private: System::Void bt_reset_recipedir_Click(System::Object^ sender, System::EventArgs^ e) {
		bg_reset_printrecipe->RunWorkerAsync();
		this->tb_selrecipe->Text = "-";
	}
	private: System::Void lb_printrecipe_Click(System::Object^ sender, System::EventArgs^ e) {
		if (lb_printrecipe->SelectedItems->Count > 0) {
			this->tb_selrecipe->Text = this->lb_printrecipe->SelectedItems[0]->ToString();
		}
	}

	private: System::Void bt_print_start_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->tb_seldata->Text != "-" && this->tb_selrecipe->Text != "-") {

			this->tb_prdata->Text = this->tb_seldata->Text;
			this->tb_prrecipe->Text = this->tb_selrecipe->Text;

			this->tb_seldata->Text = "-";
			this->tb_selrecipe->Text = "-";
			
			this->printstatus = STATUS::PRINTING;
			this->tb_status->Text = "PRINTING";

			bg_printcontrol->RunWorkerAsync();
		}
		else {
			MessageBox::Show("Please Select Printing Data and Recipe");
		}
	}
	private: System::Void bt_print_pause_Click(System::Object^ sender, System::EventArgs^ e) {
		this->printstatus = STATUS::PRINTING_PAUSE;
	}
	private: System::Void bt_print_abort_Click(System::Object^ sender, System::EventArgs^ e) {
		this->printstatus = STATUS::PRINTING_ABORT;
	}
	private: System::Void bg_printcontrol_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		int interval = 0;;

		int progress = 0; this->tb_prog->Text = progress.ToString();
		int remaintime = 1000; this->tb_retime->Text = remaintime.ToString();
		int current_layer = 0; this->tb_currlay->Text = current_layer.ToString();
		int total_layer = 100; this->tb_totalay->Text = total_layer.ToString();
		 
		while (true) {
			if (this->printstatus == STATUS::PRINTING_PAUSE) {
				continue;
			}
			else if (this->printstatus == STATUS::PRINTING) {
				interval++;
				remaintime--; this->tb_retime->Text = remaintime.ToString();
				if (interval >= 10) {
					progress++; this->tb_prog->Text = progress.ToString();
					current_layer++; this->tb_currlay->Text = current_layer.ToString();
					interval = 0;
				}
			}
			else {
				break;
			}

			Sleep(1000);
		}
	}
	private: System::Void bg_printcontrol_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (this->printstatus == STATUS::PRINTING_FINISH) {
			this->tb_status->Text = "PRINTING FINISH";

		}
		else if (this->printstatus == STATUS::PRINTING_ABORT) {
			this->tb_status->Text = "PRINTING ABORT";
		}
		else {
			MessageBox::Show("INVALID PRINT SEQUENCE END!!!");
		}
	}

	private: System::Void bt_start_mqtt_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pr_state->initProcess();
		this->bg_process_status->RunWorkerAsync();
	}
	private: System::Void bg_process_status_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		while (true) {
			if (!this->pr_state->checkStatus()) {
				std::cout << "\n===========================================================================\nProcess is Dead\n===========================================================================\n\n";
				Sleep(3000);
				this->pr_state->initProcess();
			}
			else {
				std::cout << "\n===========================================================================\nProcess is Alive\n===========================================================================\n\n";
			}
			Sleep(5000);
		}
	}
};
}
