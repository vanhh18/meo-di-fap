#include <stdio.h>

struct Patient {
    int ID;
    char name[50];
    int age;
    char gender;
    int phone_number;
};

struct Medical_Record{
    struct Patient patient;
    char date[20];
    char symptoms[100];
    char disease[50];
    char medications[100];
    char instruction[200];         
    int bill;
    int insurance;
};

void writeRecord(struct Medical_Record record) {
    FILE *file = fopen("records.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%d\t%d\n", record.patient.ID, record.patient.name, record.patient.age, record.patient.gender, record.date, record.symptoms, record.disease, record.medications, record.instruction, record.bill, record.insurance);

    fclose(file);
}

void readRecords() {
    struct Medical_Record record;
    FILE *file = fopen("records.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%d %[^\t] %d %c %[^\t] %[^\t] %[^\t] %[^\t] %d %d", &record.patient.ID, record.patient.name, &record.patient.age, &record.patient.gender, record.date, record.symptoms, record.disease, record.medications, &record.bill, &record.insurance) != EOF) {
        printf("Patient ID: %d\n", record.patient.ID);
        printf("Name: %s\n", record.patient.name);
        printf("Age: %d\n", record.patient.age);
        printf("Gender: %c\n", record.patient.gender);
        printf("Date: %s\n", record.date);
        printf("Symptoms: %s\n", record.symptoms);
        printf("Disease: %s\n", record.disease);
        printf("Medications: %s\n", record.medications);
        printf("Instruction: %s\n", record.instruction);
        printf("Bill: %d\n", record.bill);
        printf("Insurance: %d\n", record.insurance);
        printf("\n");
    }

    fclose(file);
}

int main() {
    struct Patient newPatient;
    char choice;

    printf("Do you want to add a record? (y/n): ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character

    while (choice == 'y' || choice == 'Y') {
        printf("Enter name	: ");
        fgets(newPatient.name, sizeof(newPatient.name), stdin);
        printf("Enter age	: ");
        scanf("%d", &newPatient.age);
        printf("Enter gender	: ");
        scanf(" %c", &newPatient.gender);
        getchar(); // Consume newline character

        writeRecord(newPatient);

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline character
    }
    
    printf("Records:\n");
    readRecords();

    return 0;
}
