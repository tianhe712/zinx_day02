//
// Created by asus on 2019/7/24.
//

#include "cmd_msg.h"

cmd_msg::cmd_msg() {}

cmd_msg::~cmd_msg() {

}

void cmd_msg::setIsFrameExit(bool isFrameExit) {
    is_frame_exit = isFrameExit;
}

void cmd_msg::setOutputOpen(bool outputOpen) {
    output_open = outputOpen;
}

void cmd_msg::setEchoString(const string &echoString) {
    echo_string = echoString;
}

bool cmd_msg::isFrameExit() const {
    return is_frame_exit;
}

bool cmd_msg::isOutputOpen() const {
    return output_open;
}

const string &cmd_msg::getEchoString() const {
    return echo_string;
}
