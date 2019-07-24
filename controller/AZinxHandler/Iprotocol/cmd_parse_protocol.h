//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_CMD_PARSE_PROTOCOL_H
#define ZINX_DAY02_CMD_PARSE_PROTOCOL_H

#include "head.h"
//回显业务
#include "controller/AZinxHandler/Irole/echo_role.h"
//用户数据
#include "controller/UserData/cmd_msg.h"

class cmd_parse_protocol : public Iprotocol {
public:

    virtual ~cmd_parse_protocol();

    UserData *raw2request(std::string _szInput) override;

    string *response2raw(UserData &_oUserData) override;

    static cmd_parse_protocol *getMInstance();

protected:

    Irole *GetMsgProcessor(UserDataMsg &_oUserDataMsg) override;

    Ichannel *GetMsgSender(BytesMsg &_oBytes) override;

private:

    cmd_parse_protocol();

    static cmd_parse_protocol m_instance;
    string szInputChannelInfo;

};


#endif //ZINX_DAY02_CMD_PARSE_PROTOCOL_H
