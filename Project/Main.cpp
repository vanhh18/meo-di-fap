#include "header.h"
#include "HealthRecord.h"
#include "MedicalSystem.h"

int main() {
    MedicalSystem medicalSystem(RECORDS_FILE);

    medicalSystem.welcomeScreen();
    medicalSystem.title();
    medicalSystem.loginScreen();
    return 0;
}