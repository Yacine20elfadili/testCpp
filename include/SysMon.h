#ifndef SYSMON_H
#define SYSMON_H

#include "CpuMonitor.h"
#include "MemoryMonitor.h"
#include "ProcessMonitor.h"

#include <string>
using namespace std;

int updateInterval;
bool fullLog;

int run();
string exportAsText();
string exportAsCSV();
bool update(CpuMonitor& cpuMon, MemoryMonitor& memMon, ProcessMonitor& procMon);
string getTime();
string getInfo(string type);
void log();

#endif
