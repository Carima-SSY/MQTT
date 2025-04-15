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
public:
	Process_State(String^ path);

	bool initProcess();
	bool checkStatus();
	bool killProcess();
};