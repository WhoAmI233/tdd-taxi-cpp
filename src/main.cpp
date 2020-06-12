#include <iostream>
#include "taxi.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: tdd_taxi_cpp path_to_input_file" << std::endl;
        return 1;
    }

    // TODO(you): 请将包含里程数据的文本文件作为程序的输入
    //            读取文件中的每一行作为一次里程
    //            计算每一次里程的金额，打印到标准输出，并分行
    Taxi taxi;
    std::string ret = taxi.call(argv[1]);
    if (ret != "")
    {
        std::cerr << ret << std::endl;
        return 1;
    }
    std::cout << taxi.getResult() << std::endl;
    return 0;
}
