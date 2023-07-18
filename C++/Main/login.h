#pragma once
#include "medicalSystem.h"

void MedicalSystem::loginScreen() {
    int attempts = 0;
    string username, password;
    const string originalUsername = "admin";
    const string originalPassword = "12345";

    do {
        cout << "\n\n\n\n\t\t\t\tEnter your Username and Password :)\n";
        cout << "\n\n\n\t\t\t\t\tUSERNAME: ";
        cin >> username;

        cout << "\n\n\t\t\t\t\tPASSWORD: ";
        cin >> password;

        if (username == originalUsername && password == originalPassword) {
            cout << "\n\n\n\t\t\t\t\t...Login Successful...\n";
            cin.get();
            mainMenu();
            break;
        } else {
            cout << "\n\t\t\tPassword is incorrect. Try Again :)\n";
            attempts++;
            cin.get();
        }
    } while (attempts <= 2);

    if (attempts > 2) {
        cout << "You have crossed the limit. You cannot login. :(\n";
        cin.get();
        exit(0);
    }
}