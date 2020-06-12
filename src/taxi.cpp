#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "taxi.h"

Taxi::Taxi()
{
}

std::string Taxi::call(std::string input_file_path)
{
    std::string ret = "";
    std::ifstream input_file;
    m_result = "";

    input_file.open(input_file_path);
    if (input_file.is_open())
    {
        std::string line;
        while (std::getline(input_file, line))
        {
            bool result = analysisInputText(line);

            if (result != true)
            {
                ret = "Failed to parse line: " + line + " in file: " + input_file_path;
                break;
            }
            std::stringstream ss;
            ss << "收费" << calculate() << "元" << std::endl;
            m_result += ss.str();
        }
    }
    else
    {
        ret = "Failed to open file: " + input_file_path;
    }
    input_file.close();
    return ret;
}

/**
1. 不大于2公里时只收起步价6元。
2. 超过2公里的部分每公里收取0.8元。
3. 超过8公里的部分，每公里加收50%长途费。
4. 停车等待时加收每分钟0.25元。
5. 最后计价的时候司机会四舍五入只收到元。
*/
unsigned int Taxi::calculate()
{
#define BASE_DISTANCE 2
#define LONG_DISTANCE 8

    unsigned int distance = m_distance;
    unsigned int wait = m_waittime;

    float bill = (distance > 0) ? 6.0 : 0;
    if (distance > BASE_DISTANCE)
    {
        bill += (distance - BASE_DISTANCE) * 0.8;
    }
    if (distance > LONG_DISTANCE)
    {
        bill += (distance - LONG_DISTANCE) * 0.8 * 0.5;
    }
    if (wait > 0)
    {
        bill += wait * 0.25;
    }
    return round(bill);
}

bool Taxi::analysisInputText(std::string input_text)
{
    unsigned int distance = 0;
    unsigned int wait_time = 0;
    bool ret = false;

    std::string::size_type km_index = input_text.find("公里");
    std::string::size_type wait_start = input_text.find("等待");
    std::string::size_type wait_end = input_text.find("分钟");

    if (km_index == std::string::npos ||
        wait_start == std::string::npos ||
        wait_end == std::string::npos)
    {
        std::cout << "1:" << km_index << wait_start << wait_end << std::endl;
        return ret;
    }

    wait_start += std::string("等待").length();
    if (wait_end <= wait_start)
    {
        std::cout << "2:" << km_index << wait_start << wait_end << std::endl;
        return ret;
    }

    std::string km_str = input_text.substr(0, km_index);
    distance = std::stol(km_str);

    std::string wait_str = input_text.substr(wait_start, wait_end - wait_start);
    wait_time = std::stol(wait_str);

    m_distance = distance;
    m_waittime = wait_time;
    return true;
}