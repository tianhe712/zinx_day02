//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_MY_TCPDATA_H
#define ZINX_DAY02_MY_TCPDATA_H

#include "head.h"
#include "controller/AZinxHandler/Iprotocol/cmd_parse_protocol.h"

class my_tcpData : public ZinxTcpData {
public:
    my_tcpData(int fd);

    virtual ~my_tcpData();

    AZinxHandler *GetInputNextStage(BytesMsg &_oInput) override;

};


#endif //ZINX_DAY02_MY_TCPDATA_H
