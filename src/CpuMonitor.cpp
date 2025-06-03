#include "CpuMonitor.h"
#include <iostream>


CpuMonitor::CpuMonitor() {
    CPU.nbrCPU = 0;
    CPU.frequency = 0.0;
    CPU.frequencyMax = 0.0;
}


bool CpuMonitor::update() {
    return false; 
}

float CpuMonitor::getCpuUsage() {
    return 0.0f; 
}

float CpuMonitor::getCpuFreq() {
    return CPU.frequency;
}

string CpuMonitor::getCpuInfo() {
    return ""; 
}

CpuMonitor::~CpuMonitor() {}