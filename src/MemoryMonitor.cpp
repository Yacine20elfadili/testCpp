#include "MemoryMonitor.h"
#include <iostream>

MemoryMonitor::MemoryMonitor() {
    RAM.totalMemInMb = 0;
    RAM.freeMem = 0;
    RAM.SwapMeminMb = 0;
    RAM.freeSwp = 0;
}


bool MemoryMonitor::update() {
    return false; 
}

unsigned long long MemoryMonitor::getTotalMemory() {
    return (RAM.totalMemInMb * 1024 * 1024);
}

unsigned long long MemoryMonitor::getFreeMemory() {
    return (RAM.freeMem * 1024 * 1024);
}

unsigned long long MemoryMonitor::getTotalSwap() {
    return (RAM.SwapMeminMb * 1024 * 1024);
}

unsigned long long MemoryMonitor::getUsedSwap() {
    return 0; 
}

double MemoryMonitor::getMemoryUsagePercentage() {
    return 0; 
}

double MemoryMonitor::getSwapUsagePercentage() {
    return 0; 
}

MemoryMonitor::~MemoryMonitor() {}
