//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_EXIT_FRAMEWORK_ROLE_H
#define ZINX_DAY02_EXIT_FRAMEWORK_ROLE_H

#include "head.h"
//用户数据
#include "controller/UserData/cmd_msg.h"

class exit_framework_role : public Irole {
public:
    bool Init() override;

    UserData *ProcMsg(UserData &_poUserData) override;

    void Fini() override;

};


#endif //ZINX_DAY02_EXIT_FRAMEWORK_ROLE_H
