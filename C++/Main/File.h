#pragma once
#include "medicalSystem.h"
#include <iomanip>

void MedicalSystem::saveToFile() {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    outputFile << left << setw(20) << "Patient ID" << setw(30) << "Patient Name" << setw(15) << "Record ID" << setw(15)
               << "Date" << setw(20) << "Disease" << endl;
    outputFile << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    for (const auto& record : records) {
        outputFile << left << setw(20) << record.getPatientID() << setw(30) << record.getPatientName() << setw(15)
                 << record.getRecordID() << setw(15) << record.getDate() << setw(20) << record.getDisease() << endl;
    }
    outputFile.close();
}

void MedicalSystem::readFromFile() {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string headerLine;
    string separatorLine;
    getline(inputFile, headerLine);
    getline(inputFile, separatorLine);

    string patientID, patientName, recordID, date, disease;
    while (inputFile >> patientID >> patientName >> recordID >> date >> disease) {
        HealthRecord newRecord(patientID, patientName, recordID, date, disease);
        records.push_back(newRecord);
    }

    inputFile.close();
}