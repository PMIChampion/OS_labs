#include <gtest/gtest.h>
#include <parent.hpp>
#include <sstream>
#include <vector>
#include <numeric>
#include <filesystem>

namespace fs = std::filesystem;

void TestParent(const std::string& input, const std::string& expectedOutput) {
    std::stringstream inFile(input);
    std::stringstream outFile;

    const char* pathToChild1 = getenv("PATH_TO_CHILD");

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

TEST(ParentTest, ConvertsStringCorrectly) {
    std::string input = "100 2 5\n";
    std::string expected_output = "10\n"; 
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesNoSpaces) {
    std::string input = "25 5 5\n";
    std::string expected_output = "1\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesOnlySpaces) {
    std::string input = "1000 1 1\n";
    std::string expected_output = "1000";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesEmptyString) {
    std::string input = "5 5 1";
    std::string expected_output = "1";
    TestParent(input, expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
