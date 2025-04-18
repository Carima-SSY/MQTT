#pragma once
#include <iostream>
#include <stdio.h>
using namespace System;
using namespace System::Diagnostics;
using namespace System::Windows::Forms;

public ref class Process_State {
private: 
	Process^ mqtt_process;

	String^ process_path;
	String^ process_name;
public:
	Process_State(String^ path, String^ name);

	bool initProcess();
	bool checkStatus();
	bool killProcess();
};