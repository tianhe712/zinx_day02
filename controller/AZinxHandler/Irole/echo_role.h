//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_ECHO_ROLE_H
#define ZINX_DAY02_ECHO_ROLE_H

#include "head.h"
//协议层
#include "controller/AZinxHandler/Iprotocol/cmd_parse_protocol.h"
//用户数据
#include "controller/UserData/cmd_msg.h"

class echo_role : public Irole {
public:
    echo_role();

    virtual ~echo_role();

    bool Init() override;

    UserData *ProcMsg(UserData &_poUserData) override;

    void Fini() override;

};


#endif //ZINX_DAY02_ECHO_ROLE_H
