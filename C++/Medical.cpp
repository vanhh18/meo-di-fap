#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class HealthRecord {
private:
    string recordID;
    string date;
    string disease;

public:
    HealthRecord(const string& recordID, const string& date, const string& disease) {
        this->recordID = recordID;
        this->date = date;
        this->disease = disease;
    }

    string getRecordID() const {
        return recordID;
    }

    string getDate() const {
        return date;
    }

    string getDisease() const {
        return disease;
    }
};

class Patient {
private:
    vector<HealthRecord> records;
    string fileName;

public:
    Patient(const string& filename);
    void addRecord();
    void searchByDate();
    void searchByDisease();
    void saveToFile();
};

Patient::Patient(const string& filename) : fileName(filename) {}

void Patient::addRecord() {
    system("cls");
    string recordID, date, disease;
    cout << "Enter record ID: ";
    cin >> recordID;
    cout << "Enter date: ";
    cin.ignore();
    getline(cin, date);
    cout << "Enter disease: ";
    getline(cin, disease);

    HealthRecord newRecord(recordID, date, disease);
    records.push_back(newRecord);
    cout << "Record added successfully!" << endl;
    saveToFile();
}

void Patient::searchByDate() {
    system("cls");
    string searchDate;
    cout << "Enter date: ";
    cin.ignore();
    getline(cin, searchDate);

    vector<HealthRecord>::iterator it = find_if(records.begin(), records.end(), [&](const HealthRecord& record) {
        return record.getDate() == searchDate;
    });

    if (it != records.end()) {
        cout << "Records on " << searchDate << ":" << endl;
        cout << "----------------------" << endl;
        while (it != records.end() && it->getDate() == searchDate) {
            cout << "Record ID: " << it->getRecordID() << ", Date: " << it->getDate() << ", Disease: " << it->getDisease() << endl;
            ++it;
        }
        cout << "----------------------" << endl;
    } else {
        cout << "No records found for the given date." << endl;
    }
}

void Patient::searchByDisease() {
    system("cls");
    string searchDisease;
    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, searchDisease);

    vector<HealthRecord>::iterator it = find_if(records.begin(), records.end(), [&](const HealthRecord& record) {
        return record.getDisease() == searchDisease;
    });

    if (it != records.end()) {
        cout << "Records with disease " << searchDisease << ":" << endl;
        cout << "----------------------" << endl;
        while (it != records.end() && it->getDisease() == searchDisease) {
            cout << "Record ID: " << it->getRecordID() << ", Date: " << it->getDate() << ", Disease: " << it->getDisease() << endl;
            ++it;
        }
        cout << "----------------------" << endl;
    } else {
        cout << "No records found for the given disease." << endl;
    }
}

void Patient::saveToFile() {
    ofstream outputFile(fileName);

    for (const auto& record : records) {
        outputFile << "Record ID: " << record.getRecordID() << ", Date: " << record.getDate() << ", Disease: " << record.getDisease() << endl;
    }

    outputFile.close();
    cout << "Data saved to file!" << endl;
}

int main() {
    Patient patient("health_records.txt");

    int choice;
    do {
        system("cls");
        cout << "Patient Health Record Management System" << endl;
        cout << "1. Add a Record" << endl;
        cout << "2. Search by Date" << endl;
        cout << "3. Search by Disease" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                patient.addRecord();
                cout << endl << "Press any key to continue." << endl;
                break;
            case 2:
                patient.searchByDate();
                cout << endl << "Press any key to continue." << endl;
                break;
            case 3:
                patient.searchByDisease();
                cout << endl << "Press any key to continue." << endl;
                break;
            case 4:
                system("cls");
                cout << "Exiting the program..." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please try again." << endl;
        }
        cin.ignore();
        cin.get(); // Wait for user input before continuing
    } while (choice != 4);

    return 0;
}
