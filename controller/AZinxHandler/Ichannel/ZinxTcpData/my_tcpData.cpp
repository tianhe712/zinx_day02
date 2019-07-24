//
// Created by asus on 2019/7/24.
//

#include "my_tcpData.h"

my_tcpData::my_tcpData(int fd) : ZinxTcpData(fd) {}

my_tcpData::~my_tcpData() {

}

AZinxHandler *my_tcpData::GetInputNextStage(BytesMsg &_oInput) {
    return cmd_parse_protocol::getMInstance();
}
