//
// Created by asus on 2019/7/24.
//

#include "output_mng_role.h"

bool output_mng_role::Init() {
    return true;
}

UserData *output_mng_role::ProcMsg(UserData &_poUserData) {
    GET_REF2DATA(cmd_msg, cmd, _poUserData);
    if (m_channel == NULL) {
        m_channel = ZinxKernel::Zinx_GetChannel_ByInfo("stdout_channel");
    }
    if (cmd.isOutputOpen() == true) {
        //打开输出通道
        ZinxKernel::Zinx_Add_Channel(*m_channel);
    } else {
        //关闭输出通道
        ZinxKernel::Zinx_Del_Channel(*m_channel);
    }
    return nullptr;
}

void output_mng_role::Fini() {

}
