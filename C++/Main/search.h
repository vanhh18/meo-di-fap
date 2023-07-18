#pragma once
#include "medicalSystem.h"

void MedicalSystem::searchByPatientID() {
    system("cls");
    string searchPatientID;
    cout << "Enter patient ID: ";
    cin.ignore();
    getline(cin, searchPatientID);
    bool found = false;

    for (const auto& record : records) {
        if (record.getPatientID() == searchPatientID) {
            if (!found) {
                cout << "Records for patient with ID " << searchPatientID << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Patient ID: " << record.getPatientID() << ", Patient Name: " << record.getPatientName()
                 << ", Record ID: " << record.getRecordID() << ", Date: " << record.getDate()
                 << ", Disease: " << record.getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given patient ID." << endl;
    }
}

void MedicalSystem::searchByRecordID() {
    system("cls");
    string searchRecordID;
    cout << "Enter record ID: ";
    cin.ignore();
    getline(cin, searchRecordID);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getRecordID() == searchRecordID) {
            if (!found) {
                cout << "Records with record ID " << searchRecordID << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given record ID." << endl;
    }
}

void MedicalSystem::searchByDate() {
    system("cls");
    string searchDate;
    cout << "Enter date: ";
    cin.ignore();
    getline(cin, searchDate);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getDate() == searchDate) {
            if (!found) {
                cout << "Records with date " << searchDate << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given date." << endl;
    }
}

void MedicalSystem::searchByDisease() {
    system("cls");
    string searchDisease;
    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, searchDisease);

    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getDisease() == searchDisease) {
            if (!found) {
                cout << "Records with disease " << searchDisease << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given disease." << endl;
    }
}

void MedicalSystem::searchRecord() {
    system("cls");
    int choice;
    title();
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t1. Search by Record ID\n";
    cout << "\t\t\t\t2. Search by Patient ID\n";
    cout << "\t\t\t\t3. Search by Date\n";
    cout << "\t\t\t\t4. Search by Disease\n";
    cout << "\t\t\t\t5. Back to Main Menu\n";
    cout << "\n\n\n \n\t\t\t\tChoose from 1 to 5: ";
    cin >> choice;

    switch (choice) {
        case 1:
            searchByRecordID();
            break;
        case 2:
            searchByPatientID();
            break;
        case 3:
            searchByDate();
            break;
        case 4:
            searchByDisease();
            break;
        case 5:
            mainMenu();
            break;
        default:
            cout << "\t\t\tInvalid entry. Please enter the right option :)\n";
            cin.ignore();
            cin.get();
            searchRecord();
    }
}