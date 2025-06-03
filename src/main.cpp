#include <iostream>
#include "SysMon.h"
#include <cstring>
using namespace std;

int updateInterval = 1000; // Default 1 second in milliseconds
bool fullLog = false;

void displayHelp() {
    cout << "SysMon-cpp - System Monitor" << endl;
    cout << "Usage: ./sysmon [OPTIONS]" << endl;
    cout << "Options:" << endl;
    cout << "  --help                 Display this help message" << endl;
    cout << "  --export <path>        Export data to specified file" << endl;
    cout << "  --update-interval <ms> Set update interval in milliseconds" << endl;
    cout << "  --full-log             Enable full logging" << endl;
}

void parseArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            displayHelp();
            exit(0);
        }
        else if (strcmp(argv[i], "--update-interval") == 0 && i + 1 < argc) {
            updateInterval = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "--full-log") == 0) {
            fullLog = true;
        }
        else if (strcmp(argv[i], "--export") == 0) {
            fullLog = true;
        }
    }
}

int main(int argc, char* argv[]) {
    parseArguments(argc, argv);

    CpuMonitor cpuMonitor;
    MemoryMonitor memoryMonitor;
    ProcessMonitor processMonitor;

    
    cout << "==============Welcome to SYSMON-CPP !!!==============" << endl;
    cout << "Update interval: " << updateInterval << "ms" << endl;
    cout << "Press Ctrl+C to exit" << endl << endl;

    while (true){

    }

    return 0;
}

string exportAsText() {
    return "";
}

string exportAsCSV() {
    return "";
}

bool update(CpuMonitor& cpuMon, MemoryMonitor& memMon, ProcessMonitor& procMon) {

    bool cpuUpdate = cpuMon.update();
    bool memUpdate = memMon.update();
    bool procUpdate = procMon.update();
    
    return cpuUpdate && memUpdate && procUpdate;
}

string getTime() {
    time_t now = time(0);
    char* timeStr = ctime(&now);
    string result(timeStr);
    result.pop_back(); // Remove newline
    return result;
}

string getInfo(string type) {
    return "";
}

void log() {
    cout << "Logging system information..." << endl;
}
