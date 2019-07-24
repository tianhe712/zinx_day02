//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_OUTPUT_MNG_ROLE_H
#define ZINX_DAY02_OUTPUT_MNG_ROLE_H

#include "head.h"
//用户数据
#include "controller/UserData/cmd_msg.h"

class output_mng_role : public Irole {
public:
    bool Init() override;

    UserData *ProcMsg(UserData &_poUserData) override;

    void Fini() override;

private:
    Ichannel *m_channel = NULL;
};


#endif //ZINX_DAY02_OUTPUT_MNG_ROLE_H
