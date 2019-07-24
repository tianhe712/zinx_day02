//
// Created by asus on 2019/7/24.
//

#include "my_tcpconnFact.h"

//返回一个TCP数据通道对象
ZinxTcpData *my_tcpconnFact::CreateTcpDataChannel(int _fd) {
    return new my_tcpData(_fd);
}
