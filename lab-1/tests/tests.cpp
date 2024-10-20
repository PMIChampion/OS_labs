#include <gtest/gtest.h>
#include <string>
#include <array>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <filesystem>
#include "parent.hpp"

namespace fs = std::filesystem;

void TestParent(const std::string& input, const std::string& expectedOutput) {
    std::stringstream inFile(input);
    std::stringstream outFile;

    const char* pathToChild1 = getenv("WAY_TO_FILE");

    if (pathToChild1 != nullptr) {
        if (fs::exists(pathToChild1)) {
            ParentProcess(pathToChild1, inFile, outFile);
            std::string result;
            std::string expectedLine;
            std::istringstream expectedStream(expectedOutput);
            bool match = true;

            while (std::getline(expectedStream, expectedLine)) {
                if (!std::getline(outFile, result) || result != expectedLine) {
                    match = false;
                    break;
                }
            }

            if (std::getline(outFile, result)) {
                match = false;
            }

            EXPECT_TRUE(match);
        } else {
            std::cout << "PATH DOES NOT EXIST" << std::endl;
        }
    } else {
        std::cout << "ENV VAR DOES NOT EXIST" << std::endl;
    }
}

TEST(ParentTest, Correct_Input) {
    std::string input = "100 10 10\n";
    std::string expected_output = "Результат: 1\n"; 
    TestParent(input, expected_output);
}

TEST(ParentTest, Correct_Input_2) {
    std::string input = "50 25 1\n";
    std::string expected_output = "Результат: 2\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, Zeros_Input) {
    std::string input = "0 0 0\n";
    std::string expected_output = "Делить на ноль нельзя!";
    TestParent(input, expected_output);
}

TEST(ParentTest, Bad_Input) {
    std::string input = "a b c";
    std::string expected_output = "Некорректный ввод";
    TestParent(input, expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}