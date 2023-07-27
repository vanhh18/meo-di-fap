#pragma once
#include "medicalSystem.h"
#include <iomanip>

void MedicalSystem::searchByDate() {
    system("cls");
    string searchDate;
    cout << "Enter date: ";
    cin.ignore();
    getline(cin, searchDate);
    bool found = false;

    cout << left << setw(20) << "Patient ID" << setw(30) << "Patient Name" << setw(15) << "Record ID" << setw(15)
         << "Date" << setw(20) << "Disease" << endl;
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    for (const auto& record : records) {
        if (record.getDate() == searchDate) {
            cout << left << setw(20) << record.getPatientID() << setw(30) << record.getPatientName() << setw(15)
                 << record.getRecordID() << setw(15) << record.getDate() << setw(20) << record.getDisease() << endl;
            found = true;
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

    cout << left << setw(20) << "Patient ID" << setw(30) << "Patient Name" << setw(15) << "Record ID" << setw(15)
         << "Date" << setw(20) << "Disease" << endl;
    cout << setfill('=') << setw(100) << "" << setfill(' ') << endl;

    for (const auto& record : records) {
        if (record.getDisease() == searchDisease) {
            cout << left << setw(20) << record.getPatientID() << setw(30) << record.getPatientName() << setw(15)
                 << record.getRecordID() << setw(15) << record.getDate() << setw(20) << record.getDisease() << endl;
            found = true;
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