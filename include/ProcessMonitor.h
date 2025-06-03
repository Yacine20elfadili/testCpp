#ifndef PROCESSMONITOR_H
#define PROCESSMONITOR_H

#include <string>
#include <vector>

using namespace std;

class ProcessMonitor {
private:
    int *PID;
    struct AP{
        string user;
        float cpu ;
        float memory;
        struct {
            string startTime;
            string duration;
        } time;
        string pathName;
    };
    vector<AP> ap;
    int nbrProcess;
public:
    ProcessMonitor();
    
    bool update();
    AP getProcess(int index);
    string getProcessInfo();
    
    ~ProcessMonitor();
};

#endif