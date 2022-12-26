#pragma once

#include <Windows.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>

#include "config.h"

void cheatThread();
uintptr_t GetPointerAddress(uintptr_t ptr, std::vector<uintptr_t> offsets);

void initThread();
void ammoThread();
void healthThread();
void flowerThread();