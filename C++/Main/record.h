#pragma once
#include "medicalSystem.h"

void MedicalSystem::listRecords() {
    system("cls");
    title();
    cout << "Patient Records:" << endl;
    cout << "----------------------" << endl;
    if (records.empty()) {
        cout << "No records found." << endl;
    } else {
        for (const auto& record : records) {
            cout << "Record ID: " << record.getRecordID() << ", Patient ID: " << record.getPatientID()
                << ", Patient Name: " << record.getPatientName() << ", Date: " << record.getDate()
                << ", Disease: " << record.getDisease() << endl;
        }
    }
}

void MedicalSystem::editRecord() {
    system("cls");
    string searchRecordID;
    cout << "Enter record ID to edit: ";
    cin.ignore();
    getline(cin, searchRecordID);
    bool found = false;

    for (auto& record : records) {
        if (record.getRecordID() == searchRecordID) {
            found = true;

            cout << "Editing Record ID: " << record.getRecordID() << endl;
            cout << "Enter new patient ID: ";
            string newPatientID;
            getline(cin, newPatientID);
            record.setPatientID(newPatientID);

            cout << "Enter new patient name: ";
            string newPatientName;
            getline(cin, newPatientName);
            record.setPatientName(newPatientName);

            cout << "Enter new date: ";
            string newDate;
            getline(cin, newDate);
            record.setDate(newDate);

            cout << "Enter new disease: ";
            string newDisease;
            getline(cin, newDisease);
            record.setDisease(newDisease);

            cout << "Record updated successfully!" << endl;
            saveToFile(); // Update the file after editing the record
            break;
        }
    }

    if (!found) {
        cout << "No records found for the given record ID." << endl;
    }
}

void MedicalSystem::addRecord() {
    system("cls");
    string patientID, patientName, recordID, date, disease;
    cout << "Enter patient ID: ";
    cin >> patientID;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, patientName);
    bool isDuplicate;
    do {
        isDuplicate = false;
        cout << "Enter record ID: ";
        getline(cin, recordID);

        for (const auto& record : records) {
            if (record.getRecordID() == recordID) {
                isDuplicate = true;
                cout << "Record ID is already taken. Please enter a different one." << endl;
                break;
            }
        }
    } while (isDuplicate);
    cout << "Enter date: ";
    getline(cin, date);
    cout << "Enter disease: ";
    getline(cin, disease);

    HealthRecord newRecord(patientID, patientName, recordID, date, disease);
    records.push_back(newRecord);
    cout << "Record added successfully!" << endl;
    saveToFile();
}

void MedicalSystem::removeRecordByID() {
    system("cls");
    string removeRecordID;
    cout << "Enter record ID to remove: ";
    cin.ignore();
    getline(cin, removeRecordID);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getRecordID() == removeRecordID) {
            records.erase(i);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Record with record ID " << removeRecordID << " removed successfully." << endl;
        saveToFile(); // Update the file after removing the record
    } else {
        cout << "No records found for the given record ID." << endl;
    }
}