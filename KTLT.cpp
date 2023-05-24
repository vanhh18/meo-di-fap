#include <stdio.h>
#include <string.h>
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

    fprintf(file, "%d\t%s\t%d\t%c\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n\n",
        record.patient.ID, record.patient.name, record.patient.age, record.patient.gender,
        record.date, record.symptoms, record.disease, record.medications,
        record.instruction, record.bill, record.insurance);

    fclose(file);
}

void readRecords() {
    struct Medical_Record record;
    FILE *file = fopen("records.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%d %[^\n] %d %c %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d\n", &record.patient.ID, record.patient.name, &record.patient.age, &record.patient.gender, record.date, record.symptoms, record.disease, record.medications, record.instruction, &record.bill, &record.insurance) != EOF) {
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
void searchByDisease(const char* disease) {
    struct Medical_Record record;
    FILE *file = fopen("records.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int found = 0;

   while (fscanf(file, "%s %d %c %[^\n] %[^\n] %[^\n] %[^\n] %[^\n] %d %d", record.patient.name, &record.patient.age, &record.patient.gender, record.date, record.symptoms, record.disease, record.medications, record.instruction, &record.bill, &record.insurance) != EOF) {
        if (strcmp(record.disease, disease) == 0) {
            printf("Record Found:\n");
            printf("Name: %s\n", record.patient.name);
            printf("Age: %d\n", record.patient.age);
            printf("Gender: %c\n", record.patient.gender);
            printf("Date: %s\n", record.date);
            printf("Symptoms: %s\n", record.symptoms);
            printf("Disease: %s\n", record.disease);
            printf("Medications: %s\n", record.medications);
            printf("Instructions: %s\n", record.instruction);
            printf("Bill: %d\n", record.bill);
            printf("Insurance: %d\n", record.insurance);
            printf("----------------------\n");

            found = 1;
        }
    }

    if (!found) {
        printf("No records found for the given disease.\n");
    }

    fclose(file);
}

int main() {
    struct Medical_Record newRecord;
    char choice;

    printf("Do you want to add a record? (y/n): ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character

    while (choice == 'y' || choice == 'Y') {
        printf("Enter Patient ID: ");
        scanf("%d", &newRecord.patient.ID);
        getchar(); // Consume newline character

        printf("Enter name: ");
        fgets(newRecord.patient.name, sizeof(newRecord.patient.name), stdin);
        printf("Enter age: ");
        scanf("%d", &newRecord.patient.age);
        printf("Enter gender: ");
        scanf(" %c", &newRecord.patient.gender);
        getchar(); // Consume newline character

        printf("Enter date: ");
        fgets(newRecord.date, sizeof(newRecord.date), stdin);
        printf("Enter symptoms: ");
        fgets(newRecord.symptoms, sizeof(newRecord.symptoms), stdin);
        printf("Enter disease: ");
        fgets(newRecord.disease, sizeof(newRecord.disease), stdin);
        printf("Enter medications: ");
        fgets(newRecord.medications, sizeof(newRecord.medications), stdin);
        printf("Enter instruction: ");
        fgets(newRecord.instruction, sizeof(newRecord.instruction), stdin);
        printf("Enter bill: ");
        scanf("%d", &newRecord.bill);
        printf("Enter insurance: ");
        scanf("%d", &newRecord.insurance);
        getchar(); // Consume newline character

        writeRecord(newRecord);

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline character
    }
    
    printf("Records:\n");
    readRecords();
      char searchDisease[50];
    printf("Enter a disease to search for: ");
    fgets(searchDisease, sizeof(searchDisease), stdin);
    searchByDisease(searchDisease);


    return 0;
}