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

void writeRecord(struct Patient p) {
    FILE *file = fopen("records.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s\t %d\t %c\n", p.name, p.age, p.gender);

    fclose(file);
}

void readRecords() {
    struct Patient p;
    FILE *file = fopen("records.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s %d %c", p.name, &p.age, &p.gender) != EOF) {
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Gender: %c\n", p.gender);
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
