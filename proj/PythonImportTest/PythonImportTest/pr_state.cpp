#include "pr_state.h"

Process_State::Process_State(String^ path, String^ name) {
    this->process_path = path;
    this->process_name = name;
}

bool Process_State::initProcess() {
    if (this->mqtt_process == nullptr || this->mqtt_process->HasExited) {
        System::Diagnostics::ProcessStartInfo^ psi = gcnew System::Diagnostics::ProcessStartInfo();
        psi->FileName = this->process_name;
        psi->WorkingDirectory = this->process_path;

        this->mqtt_process = Process::Start(psi);
        return true;
    }
    else {
        return false;
    }
}
bool Process_State::checkStatus() {
    if (this->mqtt_process != nullptr) {
        if (this->mqtt_process->HasExited) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
bool Process_State::killProcess() {
    if (this->mqtt_process != nullptr && !this->mqtt_process->HasExited) {
        this->mqtt_process->Kill();

        return true;
    }
    else {
        return false;
    }
}