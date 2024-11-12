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
    const char* shm_name = "/shared_memory";
    size_t shm_size = 1024;
    void* addr = CreateFileMapping(shm_name, shm_size);
    if (addr == MAP_FAILED) {
        std::cerr << "Child: Ошибка CreateFileMapping\n";
        return EXIT_FAILURE;
    }
    char* shared_data = static_cast<char*>(addr);

    std::string input(shared_data);
    std::stringstream ss(input);
    std::string result;

    int num1, num2, num3;
    if (ss >> num1 >> num2 >> num3) {
        try {
            int calc_result = calculation(num1, num2, num3);
            result = "Результат: " + std::to_string(calc_result);
        } catch (const std::runtime_error& e) {
            result = e.what();
        }
    } else {
        result = "Некорректный ввод";
    }

    // Запись результата в shared memory
    std::strncpy(shared_data, result.c_str(), shm_size);

    // Сохранение результата в файл
    std::ofstream outfile("result.txt");
    if (!outfile) {
    } else {
        outfile << result << std::endl;
        outfile.close();
    }

    CloseFileMapping(shm_name, addr, shm_size);
    std::cout << "Child process finished.\n";
    return 0;
}
