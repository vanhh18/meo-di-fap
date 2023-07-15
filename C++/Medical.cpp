#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class HealthRecord {
private:
    string patientID;
    string patientName;
    string recordID;
    string date;
    string disease;
public:
    HealthRecord(const string& patientID, const string& patientName, const string& recordID, const string& date, const string& disease) {
        this->patientID = patientID;
        this->patientName = patientName;
        this->recordID = recordID;
        this->date = date;
        this->disease = disease;
    }

    string getPatientID() const {
        return patientID;
    }

    string getPatientName() const {
        return patientName;
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

class MedicalSystem {
private:
    vector<HealthRecord> records;
    string fileName;
public:
    MedicalSystem(const string& filename);
    void addRecord();
    void searchByPatientID();
    void searchByDate();
    void searchByDisease();
    void searchByRecordID();
    void saveToFile();
    void readFromFile();
    void removeRecordByID();
};

MedicalSystem::MedicalSystem(const string& filename) : fileName(filename) {
    readFromFile();
}

void MedicalSystem::saveToFile() {
    ofstream outputFile(fileName);

    if (!outputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    for (const auto& record : records) {
        outputFile << "Patient ID: " << record.getPatientID() << ", Patient Name: " << record.getPatientName()
                   << ", Record ID: " << record.getRecordID() << ", Date: " << record.getDate()
                   << ", Disease: " << record.getDisease() << endl;
    }

    outputFile.close();
    cout << "Data saved to file!" << endl;
}


void MedicalSystem::readFromFile() {
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error opening file." << endl;
        return;
    }

    string recordLine;
    while (getline(inputFile, recordLine)) {
        size_t patientIDPos = recordLine.find(": ");
        size_t patientNamePos = recordLine.find(", Patient Name: ");
        size_t recordIDPos = recordLine.find(", Record ID: ");
        size_t datePos = recordLine.find(", Date: ");
        size_t diseasePos = recordLine.find(", Disease: ");

        if (patientIDPos != string::npos && patientNamePos != string::npos && recordIDPos != string::npos &&
            datePos != string::npos && diseasePos != string::npos) {
            string patientID = recordLine.substr(patientIDPos + 2, patientNamePos - patientIDPos - 2);
            string patientName = recordLine.substr(patientNamePos + 16, recordIDPos - patientNamePos - 16);
            string recordID = recordLine.substr(recordIDPos + 13, datePos - recordIDPos - 13);
            string date = recordLine.substr(datePos + 8, diseasePos - datePos - 8);
            string disease = recordLine.substr(diseasePos + 11);

            HealthRecord newRecord(patientID, patientName, recordID, date, disease);
            records.push_back(newRecord);
        }
    }

    inputFile.close();
}

void MedicalSystem::addRecord() {
    system("cls");
    string patientID, patientName, recordID, date, disease;
    cout << "Enter patient ID: ";
    cin >> patientID;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, patientName);
    bool isDuplicate;
    do {
        isDuplicate = false;
        cout << "Enter record ID: ";
        getline(cin, recordID);

        for (const auto& record : records) {
            if (record.getRecordID() == recordID) {
                isDuplicate = true;
                cout << "Record ID is already taken. Please enter a different one." << endl;
                break;
            }
        }
    } while (isDuplicate);
    cout << "Enter date: ";
    getline(cin, date);
    cout << "Enter disease: ";
    getline(cin, disease);

    HealthRecord newRecord(patientID, patientName, recordID, date, disease);
    records.push_back(newRecord);
    cout << "Record added successfully!" << endl;
    saveToFile();
}

void MedicalSystem::removeRecordByID() {
    system("cls");
    string removeRecordID;
    cout << "Enter record ID to remove: ";
    cin.ignore();
    getline(cin, removeRecordID);
    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
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

void MedicalSystem::searchByPatientID() {
    system("cls");
    string searchPatientID;
    cout << "Enter patient ID: ";
    cin.ignore();
    getline(cin, searchPatientID);
    bool found = false;

    for (const auto& record : records) {
        if (record.getPatientID() == searchPatientID) {
            if (!found) {
                cout << "Records for patient with ID " << searchPatientID << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Patient ID: " << record.getPatientID() << ", Patient Name: " << record.getPatientName()
                 << ", Record ID: " << record.getRecordID() << ", Date: " << record.getDate()
                 << ", Disease: " << record.getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given patient ID." << endl;
    }
}

void MedicalSystem::searchByRecordID() {
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
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given record ID." << endl;
    }
}

void MedicalSystem::searchByDate() {
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
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given date." << endl;
    }
}

void MedicalSystem::searchByDisease() {
    system("cls");
    string searchDisease;
    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, searchDisease);

    bool found = false;

    for (auto i = records.begin(); i != records.end(); ++i) {
        if (i->getDisease() == searchDisease) {
            if (!found) {
                cout << "Records with disease " << searchDisease << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << i->getRecordID() << ", Patient ID: " << i->getPatientID()
                 << ", Patient Name: " << i->getPatientName() << ", Date: " << i->getDate()
                 << ", Disease: " << i->getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given disease." << endl;
    }
}

int main() {
    MedicalSystem medicalSystem("health_records.txt");

    int choice;
    do {
        system("cls");
        cout << "MedicalSystem Health Record Management System" << endl;
        cout << "1. Add a Record" << endl;
        cout << "2. Search" << endl;
        cout << "3. Remove a Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                medicalSystem.addRecord();
                break;
            case 2: {
                system("cls");
                int searchChoice;
                cout << "Search Options:" << endl;
                cout << "1. Search by Record ID" << endl;
                cout << "2. Search by Patient ID" << endl;
                cout << "3. Search by Date" << endl;
                cout << "4. Search by Disease" << endl;
                cout << "Enter your choice: ";
                cin >> searchChoice;
                switch (searchChoice) {
                    case 1:
                        medicalSystem.searchByRecordID();
                        break;
                    case 2:
                        medicalSystem.searchByPatientID();
                        break;
                    case 3:
                        medicalSystem.searchByDate();
                        break;
                    case 4:
                        medicalSystem.searchByDisease();
                        break;
                    default:
                        system("cls");
                        cout << "Invalid search option. Please try again.";
                }
                cin.get();
                break;
            }
            case 3:
                medicalSystem.removeRecordByID();
                break;
            case 4:
                system("cls");
                cout << "Exiting the program..." << endl;
                break;
            default:
                system("cls");
                cout << "Invalid choice. Please try again." ;
        }
        cout << endl << "----------------------" << endl;
        cout << "Press any key to continue." << endl;
        cin.get(); // Wait for user input before continuing
    } while (choice != 4);

    return 0;
}

