//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_ADV_STDIN_CHANNEL_H
#define ZINX_DAY02_ADV_STDIN_CHANNEL_H

#include "head.h"
#include "controller/AZinxHandler/Iprotocol/cmd_parse_protocol.h"

class adv_stdin_channel : public Ichannel {
public:
    adv_stdin_channel();

    virtual ~adv_stdin_channel();

    bool Init() override;

    bool ReadFd(std::string &_input) override;

    bool WriteFd(std::string &_output) override;

    void Fini() override;

    int GetFd() override;

    string GetChannelInfo() override;

protected:
    AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;

};


#endif //ZINX_DAY02_ADV_STDIN_CHANNEL_H
