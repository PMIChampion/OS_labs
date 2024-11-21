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
            FAIL() << "Путь к дочернему процессу не существует";
        }
    } else {
        std::cout << "ENV VAR DOES NOT EXIST" << std::endl;
        FAIL() << "Переменная PATH_TO_CHILD не существует";
    }
}

TEST(ParentTest, ConvertsStringCorrectly) {
    std::string input = "100 2 5\n";
    std::string expected_output = "Результат: 10\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesNoSpaces) {
    std::string input = "25 5 5\n";
    std::string expected_output = "Результат: 1\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesOnlySpaces) {
    std::string input = "1000 1 1\n";
    std::string expected_output = "Результат: 1000\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesEmptyString) {
    std::string input = "5 5 1\n";
    std::string expected_output = "Результат: 1\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesMultipleLines) {
    std::string input = "100 2 5\n50 5 2\n25 5 1\n";
    std::string expected_output =
        "Результат: 10\n"  // 100 / 2 / 5 = 10
        "Результат: 5\n"   // 50 / 5 / 2 = 5
        "Результат: 5\n";  // 25 / 5 / 1 = 5
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesInvalidInput) {
    std::string input = "a b c\n";
    std::string expected_output = "Некорректный ввод\n";
    TestParent(input, expected_output);
}

TEST(ParentTest, HandlesDivisionByZero) {
    std::string input = "10 0 5\n";
    std::string expected_output = "Деление на ноль\n";
    TestParent(input, expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
