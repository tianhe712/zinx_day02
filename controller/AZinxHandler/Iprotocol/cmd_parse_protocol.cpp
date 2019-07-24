//
// Created by asus on 2019/7/24.
//

#include <controller/AZinxHandler/Irole/exit_framework_role.h>
#include <controller/AZinxHandler/Irole/output_mng_role.h>
#include "cmd_parse_protocol.h"

cmd_parse_protocol::cmd_parse_protocol() {}

cmd_parse_protocol::~cmd_parse_protocol() {

}

UserData *cmd_parse_protocol::raw2request(std::string _szInput) {
    //命令解析
    cmd_msg *pout = new cmd_msg();
    if (_szInput == "exit") {
        pout->setIsFrameExit(true);
    }
    if (_szInput == "close") {
        pout->setOutputOpen(false);
    }
    if (_szInput == "open") {
        pout->setOutputOpen(true);
    }
    pout->setEchoString(_szInput);

    return pout;
}

string *cmd_parse_protocol::response2raw(UserData &_oUserData) {
    GET_REF2DATA(cmd_msg, output, _oUserData);
    return new string(output.getEchoString());
}

Irole *cmd_parse_protocol::GetMsgProcessor(UserDataMsg &_oUserDataMsg) {
    //记录数据来源的通道信息
    szInputChannelInfo = _oUserDataMsg.szInfo;

    //判断消息内容分发到不同业务对象
    GET_REF2DATA(cmd_msg, output, *_oUserDataMsg.poUserData);
    //查找业务对象函数
    list<Irole *> role_list = ZinxKernel::Zinx_GetAllRole();
    //过滤所需的业务对象
    if (output.getEchoString() == "exit") {
        //过滤退出对象
        for (auto role : role_list) {
            if (dynamic_cast<exit_framework_role *>(role) != NULL) {
                return role;
            }
        }
    }
    if (output.getEchoString() == "close" || output.getEchoString() == "open") {
        //过滤输出开关对象
        for (auto role : role_list) {
            if (dynamic_cast<output_mng_role *>(role) != NULL) {
                return role;
            }
        }
    }
    for (auto role : role_list) {
        if (dynamic_cast<echo_role *>(role) != NULL) {
            return role;
        }
    }

    return nullptr;
}

Ichannel *cmd_parse_protocol::GetMsgSender(BytesMsg &_oBytes) {
    if (szInputChannelInfo == "stdin_channel") {
        return ZinxKernel::Zinx_GetChannel_ByInfo("stdout_channel");
    }
    return ZinxKernel::Zinx_GetChannel_ByInfo(szInputChannelInfo);
}

cmd_parse_protocol *cmd_parse_protocol::getMInstance() {
    return &m_instance;
}

cmd_parse_protocol cmd_parse_protocol::m_instance;
