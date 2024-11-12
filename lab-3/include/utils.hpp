#pragma once

#include <cstddef> 
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

void* CreateFileMapping(const char* name, size_t size);
void CloseFileMapping(const char* name, void* addr, size_t size);
pid_t CreateChild();
void Exec(const char * pathToChild);