//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_CMD_MSG_H
#define ZINX_DAY02_CMD_MSG_H

#include "head.h"

class cmd_msg : public UserData {
public:
    cmd_msg();

    virtual ~cmd_msg();

    void setIsFrameExit(bool isFrameExit);

    void setOutputOpen(bool outputOpen);

    void setEchoString(const string &echoString);

    bool isFrameExit() const;

    bool isOutputOpen() const;

    const string &getEchoString() const;

private:
    bool is_frame_exit = false;
    bool output_open = true;
    string echo_string;
};


#endif //ZINX_DAY02_CMD_MSG_H
