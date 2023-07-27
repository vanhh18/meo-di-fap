
#include "login.h"
#include "mainMenu.h"
#include "title.h"
#include "record.h"
#include "search.h"
#include "File.h"

#include "header.h"

int main() {
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\t\t\t\t#\t\t WELCOME TO\t\t#\n";
    cout << "\t\t\t\t#          HOSPITAL RECORD SYSTEM       #\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\n\n\n\n\n Press any key to continue......\n";
    cin.get();
    system("cls");
    MedicalSystem medicalSystem("health_records.txt");

    medicalSystem.welcomeScreen();
    medicalSystem.title();
    medicalSystem.loginScreen();
    return 0;
}