#include <iostream>
#include "SysMon.h"
#include <cstring>
#include <chrono>
#include <thread>
using namespace std;

SysMonitor sysMon;

void displayHelp() {
    cout << "==============Welcome to SYSMON-CPP !!!==============" << endl;
    cout << "Utilisation : .\\tests\\sysmon [OPTIONS]" << endl;
    cout << "Les options:" << endl;
    cout << "  --help                  Affiche l'aide avec la liste des options disponibles." << endl;
    cout << "  --export <path>         Exporte les donnees sous forme de fichier texte ou CSV." << endl;
    cout << "  --update-interval <ms>  Definit l'intervalle de mise a jour des donnees en secondes." << endl;
}

void parseArguments(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            displayHelp();
            exit(0);
        }
        else if (strcmp(argv[i], "--update-interval") == 0 && i + 1 < argc) {
            sysMon.setUpdateInterval(atoi(argv[++i]));
        }
        else if (strcmp(argv[i], "--export") == 0) {
            sysMon.exportAsText();
            sysMon.exportAsCSV();
        }
    }
}


int main(int argc, char* argv[]) {
    parseArguments(argc, argv);
    
    cout << "Update interval: " << sysMon.getUpdateInterval() << "ms" << endl;
    cout << "Press Ctrl+C to exit" << endl << endl;

    return sysMon.run();
}
