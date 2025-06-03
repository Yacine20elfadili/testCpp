#ifndef CPUMONITOR_H
#define CPUMONITOR_H

#include <string>

using namespace std;

class CpuMonitor {
private:
    struct CPU{
        short nbrCPU;
        float *usagePerCPU;
        float frequency;
        float frequencyMax;
    }CPU;

public:
    CpuMonitor();
    
    bool update();
    float getCpuUsage();
    float getCpuFreq();
    string getCpuInfo();

    ~CpuMonitor();
};

#endif