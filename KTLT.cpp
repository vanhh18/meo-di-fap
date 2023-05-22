#include <stdio.h>

struct Date{
	int day;
	int month;
	int year;	
};

struct Medical_Record{
	
};

struct Patient {
    char name[50];
    int age;
    char gender;
    struct Date date;
    int phone_number;
    struct Medical_Record record;
};

void writeRecord(struct Person p) {
    FILE *file = fopen("records.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %d %s\n", p.name, p.age, p.email);

    fclose(file);
}

void readRecords() {
    struct Person p;
    FILE *file = fopen("records.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s %d %s", p.name, &p.age, p.email) != EOF) {
        printf("Name: %s\n", p.name);
        printf("Age: %d\n", p.age);
        printf("Email: %s\n", p.email);
    }

    fclose(file);
}

int main() {
    struct Person newPerson;
    char choice;

    printf("Do you want to add a record? (y/n): ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character

    while (choice == 'y' || choice == 'Y') {
        printf("Enter name	: ");
        fgets(newPerson.name, sizeof(newPerson.name), stdin);
        printf("Enter age	: ");
        scanf("%d", &newPerson.age);
        printf("Enter email	: ");
        scanf("%s", newPerson.email);

        writeRecord(newPerson);

        printf("Do you want to add another record? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline character
    }
    
    printf("Records:\n");
    readRecords();

    return 0;
}
