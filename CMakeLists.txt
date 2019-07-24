cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME zinx_day02)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

#首先定义两个变量INC_DIR和LINK_DIR，用来表示头文件路径和库的路径：
set(INC_DIR /usr/include)
set(LINK_DIR /usr/lib)
#然后依次设置头文件目录、库目录、要链接的库：
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(libzinx.so)

add_executable(${PROJECT_NAME}
        main.cpp head.cpp head.h controller/AZinxHandler/Ichannel/ZinxTcpData/my_tcpData.cpp controller/AZinxHandler/Ichannel/ZinxTcpData/my_tcpData.h controller/IZinxTcpConnFact/my_tcpconnFact.cpp controller/IZinxTcpConnFact/my_tcpconnFact.h controller/AZinxHandler/Irole/echo_role.cpp controller/AZinxHandler/Irole/echo_role.h controller/AZinxHandler/Irole/exit_framework_role.cpp controller/AZinxHandler/Irole/exit_framework_role.h controller/AZinxHandler/Irole/output_mng_role.cpp controller/AZinxHandler/Irole/output_mng_role.h controller/AZinxHandler/Iprotocol/cmd_parse_protocol.cpp controller/AZinxHandler/Iprotocol/cmd_parse_protocol.h controller/UserData/cmd_msg.cpp controller/UserData/cmd_msg.h controller/AZinxHandler/Ichannel/adv_stdout_channel.cpp controller/AZinxHandler/Ichannel/adv_stdout_channel.h controller/AZinxHandler/Ichannel/adv_stdin_channel.cpp controller/AZinxHandler/Ichannel/adv_stdin_channel.h)

#使用如下语句完成库的链接操作：
target_link_libraries(${PROJECT_NAME} libzinx.so)

#使用多线程 报错 “对‘pthread_create’未定义的引用”解决：
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)
