#ifndef SYSMON_H
#define SYSMON_H

#include "CpuMonitor.h"
#include "MemoryMonitor.h"
#include "ProcessMonitor.h"

#include <string>
#include <chrono>
#include <thread>
#include <sstream>
#include <iomanip>
#include <ctime>

class SysMonitor : public CpuMonitor, public MemoryMonitor, public ProcessMonitor {
private:
    int updateInterval;  // Update interval in milliseconds
    bool fullLog;        // Flag for full logging

    std::string getTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

public:
    SysMonitor(int interval = 1000, bool enableFullLog = false) 
        : CpuMonitor(), 
          MemoryMonitor(), 
          ProcessMonitor(),
          updateInterval(interval),
          fullLog(enableFullLog) {}

    void setUpdateInterval(int interval) {
        updateInterval = interval;
    }
    int getUpdateInterval() {
        return updateInterval ;
    }

    void setFullLogging(bool enable) {
        fullLog = enable;
    }
    bool getFullLogging() {
        return fullLog;
    }

    bool update() {
        return CpuMonitor::update() && 
               MemoryMonitor::update() && 
               ProcessMonitor::update();
    }

    std::string getInfo(std::string type) {
        if (type == "cpu") {
            return getCpuInfo();
        }
        else if (type == "memory") {
            return "Memory Usage: " + std::to_string(getMemoryUsagePercentage()) + "% " +
                   "Swap Usage: " + std::to_string(getSwapUsagePercentage()) + "%\n";
        }
        else if (type == "process") {
            return getProcessInfo();
        }
        return "Unknown info type";
    }

    std::string exportAsText() {
        std::stringstream ss;
        ss << "=== System Monitor Report ===\n";
        ss << "Time: " << getTime() << "\n\n";
        ss << "--- CPU Information ---\n" << getInfo("cpu") << "\n";
        ss << "--- Memory Information ---\n" << getInfo("memory") << "\n";
        ss << "--- Process Information ---\n" << getInfo("process") << "\n";
        return ss.str();
    }

    std::string exportAsCSV() {
        std::stringstream ss;
        ss << "Timestamp,CPU Usage,CPU Frequency,Memory Usage,Swap Usage\n";
        ss << getTime() << "," 
           << getCpuUsage() << "," 
           << getCpuFreq() << "," 
           << getMemoryUsagePercentage() << "," 
           << getSwapUsagePercentage() << "\n";
        return ss.str();
    }


    int run(){
    try {
        while (true) {
            if (update()) {
            this_thread::sleep_for(std::chrono::milliseconds(updateInterval));
            }
        }
    }
    catch (const exception& e) {
        cerr << "error: " << e.what() << endl;
        return 1;
    }
    return 0;
}

    ~SysMonitor(){};
};

#endif
