//
// Created by asus on 2019/7/24.
//

#ifndef ZINX_DAY02_MY_TCPCONNFACT_H
#define ZINX_DAY02_MY_TCPCONNFACT_H

#include "head.h"
#include "controller/AZinxHandler/Ichannel/ZinxTcpData/my_tcpData.h"

class my_tcpconnFact : public IZinxTcpConnFact {
public:
    ZinxTcpData *CreateTcpDataChannel(int _fd) override;

};


#endif //ZINX_DAY02_MY_TCPCONNFACT_H
