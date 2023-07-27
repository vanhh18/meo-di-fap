#include "header.h"
#include "HealthRecord.h"
#include "MedicalSystem.h"

int main() {
    MedicalSystem medicalSystem("health_records.txt");

    medicalSystem.welcomeScreen();
    medicalSystem.title();
    medicalSystem.loginScreen();
    return 0;
}