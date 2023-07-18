#pragma once
#include "medicalSystem.h"

void MedicalSystem::mainMenu() {
    int choice;
    do {
        system("cls");
        title();
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t1. Add Patient Record\n";
        cout << "\t\t\t\t2. List Patient Records\n";
        cout << "\t\t\t\t3. Search Patient Record\n";
        cout << "\t\t\t\t4. Edit Patient Record\n";
        cout << "\t\t\t\t5. Delete Patient Record\n";
        cout << "\t\t\t\t6. Exit\n";
        cout << "\n\n\n \n\t\t\t\tChoose from 1 to 6: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                listRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                editRecord();
                break;
            case 5:
                removeRecordByID();
                break;
            case 6:
                system("cls");
                exit(0);
            default:
                system("cls");
                cout << "\t\t\tInvalid entry. Please enter the right option :)\n";
        }
        cout << endl << "----------------------" << endl;
        cout << "Press any key to continue." << endl;
        cin.get();
        mainMenu();
    } while (choice != 6);
}