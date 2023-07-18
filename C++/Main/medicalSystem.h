#pragma once
#include "header.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "healthRecords.h"

class MedicalSystem {
private:
    vector<HealthRecord> records;
    string fileName;
public:
    MedicalSystem(const string& filename);
    void welcomeScreen();
    void title();
    void mainMenu();
    void loginScreen();
    void listRecords();
    void editRecord();
    void searchRecord();
    void addRecord();
    void searchByPatientID();
    void searchByDate();
    void searchByDisease();
    void searchByRecordID();
    void saveToFile();
    void readFromFile();
    void removeRecordByID();
};

MedicalSystem::MedicalSystem(const string& filename) : fileName(filename) {
    readFromFile();
}

