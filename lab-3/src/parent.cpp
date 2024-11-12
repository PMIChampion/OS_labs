#include "parent.hpp"


void ParentProcess(const char * pathToChild, std::istream & streamIn, std::ostream & streamOut){
    const char* shm_name = "/shared_memory";
    size_t shm_size = 1024;
    void* addr = CreateFileMapping(shm_name, shm_size);
    char* shared_data = static_cast<char*>(addr);


    std::string line;
    std::cout << "Введите три числа через пробел: ";
    std::getline(streamIn, line);
    line += "\n";
    std::strncpy(shared_data, line.c_str(), shm_size);

    pid_t pid = CreateChild();
    //Мы в дочернем процессе
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
