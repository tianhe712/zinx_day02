//
// Created by asus on 2019/7/24.
//

#include "echo_role.h"

echo_role::echo_role() {}

echo_role::~echo_role() {

}

bool echo_role::Init() {
    return true;
}

//回显消息处理
UserData *echo_role::ProcMsg(UserData &_poUserData) {
    //取出待回显的内容
    GET_REF2DATA(cmd_msg, input, _poUserData);
    //构建待发送消息
    cmd_msg *pout = new cmd_msg();
    pout->setEchoString(input.getEchoString());
    //发送出去
    ZinxKernel::Zinx_SendOut(*pout, *(cmd_parse_protocol::getMInstance()));
    //没有后续环节
    return nullptr;
}

void echo_role::Fini() {

}
