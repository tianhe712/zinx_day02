//
// Created by asus on 2019/7/24.
//

#include "adv_stdin_channel.h"

adv_stdin_channel::adv_stdin_channel() {}

adv_stdin_channel::~adv_stdin_channel() {

}

bool adv_stdin_channel::Init() {
    return true;
}

bool adv_stdin_channel::ReadFd(std::string &_input) {
    cin >> _input;
    return true;
}

bool adv_stdin_channel::WriteFd(std::string &_output) {
    return false;
}

void adv_stdin_channel::Fini() {

}

int adv_stdin_channel::GetFd() {
    return 0;
}

string adv_stdin_channel::GetChannelInfo() {
    return "stdin_channel";
}

AZinxHandler *adv_stdin_channel::GetInputNextStage(BytesMsg &_oInput) {
    //返回协议对象
    return cmd_parse_protocol::getMInstance();
}
