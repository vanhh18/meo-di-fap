#include "screen.h"
#include "login.h"
#include "mainMenu.h"
#include "title.h"
#include "record.h"
#include "search.h"

#include "header.h"

int main() {
    MedicalSystem medicalSystem("health_records.txt");

    medicalSystem.welcomeScreen();
    medicalSystem.title();
    medicalSystem.loginScreen();
    return 0;
}