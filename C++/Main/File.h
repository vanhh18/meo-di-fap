#pragma once
#include "medicalSystem.h"

void MedicalSystem::saveToFile() {
    ofstream outputFile("health_records");

    if (!outputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    for (const auto& record : records) {
        outputFile << "Patient ID: " << record.getPatientID() << ", Patient Name: " << record.getPatientName()
                   << ", Record ID: " << record.getRecordID() << ", Date: " << record.getDate()
                   << ", Disease: " << record.getDisease() << endl;
    }

    outputFile.close();
    cout << "Data saved to file!" << endl;
}

void MedicalSystem::readFromFile() {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string recordLine;
    while (getline(inputFile, recordLine)) {
        size_t patientIDPos = recordLine.find(": ");
        size_t patientNamePos = recordLine.find(", Patient Name: ");
        size_t recordIDPos = recordLine.find(", Record ID: ");
        size_t datePos = recordLine.find(", Date: ");
        size_t diseasePos = recordLine.find(", Disease: ");

        if (patientIDPos != string::npos && patientNamePos != string::npos && recordIDPos != string::npos &&
            datePos != string::npos && diseasePos != string::npos) {
            string patientID = recordLine.substr(patientIDPos + 2, patientNamePos - patientIDPos - 2);
            string patientName = recordLine.substr(patientNamePos + 16, recordIDPos - patientNamePos - 16);
            string recordID = recordLine.substr(recordIDPos + 13, datePos - recordIDPos - 13);
            string date = recordLine.substr(datePos + 8, diseasePos - datePos - 8);
            string disease = recordLine.substr(diseasePos + 11);

            HealthRecord newRecord(patientID, patientName, recordID, date, disease);
            records.push_back(newRecord);
        }
    }

    inputFile.close();
}