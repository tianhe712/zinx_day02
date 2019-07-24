//
// Created by asus on 2019/7/24.
//

#include "exit_framework_role.h"

bool exit_framework_role::Init() {
    return true;
}

UserData *exit_framework_role::ProcMsg(UserData &_poUserData) {
    GET_REF2DATA(cmd_msg, cmd, _poUserData);
    if (cmd.isFrameExit()) {
        ZinxKernel::Zinx_Exit();
    }
    return nullptr;
}

void exit_framework_role::Fini() {

}
