#include "child.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "utils.hpp"

int calculation(int num1, int num2, int num3) {
    if (num2 == 0 || num3 == 0) {
        throw std::runtime_error("Деление на ноль");
    }
    return num1 / num2 / num3;
}

int main() {
    constexpr auto shm_name = "/shared_memory";
    size_t shm_size = 1024;
    void* addr = CreateFileMapping(shm_name, shm_size);
    if (addr == MAP_FAILED) {
        std::cerr << "Child: Ошибка CreateFileMapping\n";
        return EXIT_FAILURE;
    }
    char* shared_data = static_cast<char*>(addr);

    std::string input(shared_data);
    std::stringstream ss(input);
    std::string line;
    std::string result;

    while (std::getline(ss, line)) {
        std::stringstream line_ss(line);
        int num1, num2, num3;
        if (line_ss >> num1 >> num2 >> num3) {
            try {
                int calc_result = calculation(num1, num2, num3);
                result += "Результат: " + std::to_string(calc_result) + "\n";
            } catch (const std::runtime_error& e) {
                result += e.what();
                result += "\n";
            }
        } else {
            result += "Некорректный ввод\n";
        }
    }

    if (result.size() >= shm_size) {
        std::cerr << "Не хватка памяти\n";
        CloseFileMapping(shm_name, addr, shm_size);
        return EXIT_FAILURE;
    }
    std::strncpy(shared_data, result.c_str(), shm_size);

    std::ofstream outfile("result.txt");
    if (outfile) {
        outfile << result;
        outfile.close();
    }

    CloseFileMapping(shm_name, addr, shm_size);
    std::cout << "Child process finished.\n";
    return 0;
}
