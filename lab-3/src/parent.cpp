#include "parent.hpp"

void ParentProcess(const char * pathToChild, std::istream & streamIn, std::ostream & streamOut){
    constexpr auto shm_name = "/shared_memory";
    size_t shm_size = 1024;
    void* addr = CreateFileMapping(shm_name, shm_size);
    char* shared_data = static_cast<char*>(addr);

    std::string all_lines;
    std::cout << "Введите несколько строк, каждая содержит три числа (пустая строка для завершения ввода):\n";
    while (true) {
        std::string line;
        std::getline(streamIn, line);
        if (line.empty()) {
            break;
        }
        all_lines += line + "\n";
    }

    if (all_lines.size() >= shm_size) {
        std::cerr << "Не хватка памяти\n";
        CloseFileMapping(shm_name, addr, shm_size);
        exit(EXIT_FAILURE);
    }
    std::strncpy(shared_data, all_lines.c_str(), shm_size);

    pid_t pid = CreateChild();
    if(pid == 0){
        Exec(pathToChild);
    }else if (pid > 0){
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            perror("Ошибка ожидания дочернего процесса");
            CloseFileMapping(shm_name, addr, shm_size);
            exit(EXIT_FAILURE);
        }
        streamOut << shared_data;
        CloseFileMapping(shm_name, addr, shm_size);
    }else{
        perror("Дочерний процесс не создан");
        CloseFileMapping(shm_name, addr, shm_size);
        exit(EXIT_FAILURE);
    }
}
