#pragma once
#include "medicalSystem.h"

void MedicalSystem::welcomeScreen() {
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\t\t\t\t#\t\t WELCOME TO\t\t#\n";
    cout << "\t\t\t\t#          HOSPITAL RECORD SYSTEM       #\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\n\n\n\n\n Press any key to continue......\n";
    cin.get();
    system("cls");
}