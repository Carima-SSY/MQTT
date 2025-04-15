#include "pr_state.h"

Process_State::Process_State(String^ path) {
    this->process_path = path;
}

bool Process_State::initProcess() {
    if (this->mqtt_process == nullptr || this->mqtt_process->HasExited) {
        this->mqtt_process = gcnew Process();
        this->mqtt_process->StartInfo->FileName = this->process_path;
        this->mqtt_process->Start();

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