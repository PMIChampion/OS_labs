#include "parent.hpp"


int main(void) {
    
    ParentProcess(getenv("WAY_TO_FILE"), std::cin, std::cout);

    exit(EXIT_SUCCESS);
}