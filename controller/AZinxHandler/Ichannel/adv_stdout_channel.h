//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_ADV_STDOUT_CHANNEL_H
#define ZINX_DAY02_ADV_STDOUT_CHANNEL_H

#include "head.h"

class adv_stdout_channel : public Ichannel {
public:
    adv_stdout_channel();

    virtual ~adv_stdout_channel();

    bool Init() override;

    bool ReadFd(std::string &_input) override;

    bool WriteFd(std::string &_output) override;

    void Fini() override;

    int GetFd() override;

    string GetChannelInfo() override;

protected:
    AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;

};


#endif //ZINX_DAY02_ADV_STDOUT_CHANNEL_H
