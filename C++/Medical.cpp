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
    void searchByRecordID();
    void saveToFile();
    void readFromFile();
    void removeRecordByID();
    
};

Patient::Patient(const string& filename) : fileName(filename) {
    readFromFile();
}


void Patient::saveToFile() {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    for (const auto& record : records) {
        outputFile << "Record ID: " << record.getRecordID() << ", Date: " << record.getDate() << ", Disease: " << record.getDisease() << endl;
    }

    outputFile.close();
    cout << "Data saved to file!" << endl;
}


void Patient::readFromFile() {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string recordLine;
    while (getline(inputFile, recordLine)) {
        // Parse the record line and extract record ID, date, and disease
        // Assuming the record line has the format: "Record ID: <id>, Date: <date>, Disease: <disease>"
        size_t idPos = recordLine.find(": ");
        size_t datePos = recordLine.find(", Date: ");
        size_t diseasePos = recordLine.find(", Disease: ");

        if (idPos != string::npos && datePos != string::npos && diseasePos != string::npos) {
            string recordID = recordLine.substr(idPos + 2, datePos - idPos - 2);
            string date = recordLine.substr(datePos + 8, diseasePos - datePos - 8);
            string disease = recordLine.substr(diseasePos + 11);

            HealthRecord newRecord(recordID, date, disease);
            records.push_back(newRecord);
        }
    }

    inputFile.close();
}

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

void Patient::removeRecordByID() {
    system("cls");
    string removeRecordID;
    cout << "Enter record ID to remove: ";
    cin.ignore();
    getline(cin, removeRecordID);
    bool found = false;

    for (auto i = records.begin(); i!= records.end(); ++i) {
        if (i->getRecordID() == removeRecordID) {
            records.erase(i);
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Record with record ID " << removeRecordID << " removed successfully." << endl;
        saveToFile(); // Update the file after removing the record
    } else {
        cout << "No records found for the given record ID." << endl;
    }
}


void Patient::searchByRecordID() {
    system("cls");
    string searchRecordID;
    cout << "Enter record ID: ";
    cin.ignore();
    getline(cin, searchRecordID);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getRecordID() == searchRecordID) {
            if (!found) {
                cout << "Records with record ID " << searchRecordID << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Date: " << i->getDate() << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given record ID." << endl;
    }
}


void Patient::searchByDate() {
    system("cls");
    string searchDate;
    cout << "Enter date: ";
    cin.ignore();
    getline(cin, searchDate);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getDate() == searchDate) {
            if (!found) {
                cout << "Records with date " << searchDate << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Date: " << i->getDate() << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given date." << endl;
    }

}

void Patient::searchByDisease() {
    system("cls");
    string searchDisease;
    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, searchDisease);

    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getDate() == searchDisease) {
            if (!found) {
                cout << "Records with disease " << searchDisease << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Date: " << i->getDate() << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given disease." << endl;
    }
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
        cout << "4. Search by Record ID" << endl;
        cout << "5. Remove a record" << endl;
        cout << "6. Exit" << endl;
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
                patient.searchByRecordID();
                cout << endl << "Press any key to continue." << endl;
                break;
            case 5:
                patient.removeRecordByID();
                cout << endl << "Press any key to continue." << endl;
                break;
            case 6:
                system("cls");
                cout << "Exiting the program..." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please try again." << endl;
        }
        cin.get(); // Wait for user input before continuing
    } while (choice != 6);

    return 0;
}
