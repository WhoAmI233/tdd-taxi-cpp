#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <iostream>

#include "taxi.cpp"

#define NON_EXIST_INPUT_FILE "./RANDOM_FILE_NAME_ASDFASDFASFAQFQWASDVW.txt"
#define VALID_INPUT_FILE "./TaxiTestValidInput.txt"
#define INVALID_INPUT_FILE "./TaxiTestInvalidInput.txt"

TEST(TaxiTest, test_non_exist_input)
{
    Taxi tx;
    ASSERT_TRUE(tx.call(NON_EXIST_INPUT_FILE) != "");
}

TEST(TaxiTest, test_one_valid_line)
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file << "1公里,等待0分钟" << std::endl;
    test_file.close();

    Taxi tx;
    ASSERT_TRUE(tx.call(VALID_INPUT_FILE) == "");
    ASSERT_TRUE(tx.getResult() == "收费6元\n");
}

TEST(TaxiTest, test_four_valid_lines)
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file << "1公里,等待0分钟" << std::endl;
    test_file << "3公里,等待0分钟" << std::endl;
    test_file << "10公里,等待0分钟" << std::endl;
    test_file << "2公里,等待3分钟" << std::endl;
    test_file.close();

    Taxi tx;
    ASSERT_TRUE(tx.call(VALID_INPUT_FILE) == "");
    ASSERT_TRUE(tx.getResult() == "收费6元\n收费7元\n收费13元\n收费7元\n");
}

TEST(TaxiTest, test_one_invalid_lines)
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file << "1公里,等0分钟" << std::endl;
    test_file.close();

    Taxi tx;
    ASSERT_TRUE(tx.call(INVALID_INPUT_FILE) != "");
}

TEST(TaxiTest, test_multiple_invalid_lines_1)
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file << "1公里,等0分钟" << std::endl; // <-- invalid input
    test_file << "3公里,等待0分钟" << std::endl;
    test_file << "10公里,等待0分钟" << std::endl;
    test_file << "2公里,等待3分钟" << std::endl;
    test_file.close();

    Taxi tx;
    ASSERT_TRUE(tx.call(INVALID_INPUT_FILE) != "");
}

TEST(TaxiTest, test_multiple_invalid_lines_2)
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file << "1公里,等待0分钟" << std::endl;
    test_file << "3公里,等待分钟" << std::endl; // <-- invalid input
    test_file << "10公里,等待0分钟" << std::endl;
    test_file << "2公里,等待3分钟" << std::endl;
    test_file.close();

    Taxi tx;
    ASSERT_TRUE(tx.call(INVALID_INPUT_FILE) != "");
}
