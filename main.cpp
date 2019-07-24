#include "head.h"
//通道层
#include "controller/AZinxHandler/Ichannel/adv_stdin_channel.h"
#include "controller/AZinxHandler/Ichannel/adv_stdout_channel.h"
#include "controller/AZinxHandler/Ichannel/ZinxTcpData/my_tcpData.h"
//协议层
//业务层（角色层）
#include "controller/AZinxHandler/Irole/echo_role.h"
#include "controller/AZinxHandler/Irole/exit_framework_role.h"
#include "controller/AZinxHandler/Irole/output_mng_role.h"
//基类层
#include "controller/IZinxTcpConnFact/my_tcpconnFact.h"

int main() {
    //初始化框架
    if (ZinxKernel::ZinxKernelInit()) {
        /*通道层*/
        //创建输入通道，添加到通道环节
        adv_stdin_channel *pin = new adv_stdin_channel();
        ZinxKernel::Zinx_Add_Channel(*pin);
        //创建输出通道，添加到通道环节
        adv_stdout_channel *pout = new adv_stdout_channel();
        ZinxKernel::Zinx_Add_Channel(*pout);
        //创建监听通道，添加到通道环节
        ZinxTCPListen *plisten = new ZinxTCPListen(10010, new my_tcpconnFact());
        ZinxKernel::Zinx_Add_Channel(*plisten);
        /*业务层*/
        //创建回显业务，添加到业务环节
        echo_role *pecho = new echo_role();
        ZinxKernel::Zinx_Add_Role(*pecho);
        //创建退出业务，添加到业务环节
        exit_framework_role *pexit = new exit_framework_role();
        ZinxKernel::Zinx_Add_Role(*pexit);
        //创建输出开关业务，添加到业务环节
        output_mng_role *poutput_mng = new output_mng_role();
        ZinxKernel::Zinx_Add_Role(*poutput_mng);

        //运行，销毁框架
        ZinxKernel::Zinx_Run();
        ZinxKernel::ZinxKernelFini();
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}