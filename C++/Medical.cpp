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

    string getPatientID() const { return patientID;}

    void setPatientID(const string& newPatientID) { patientID = newPatientID;}

    string getPatientName() const { return patientName;}

    void setPatientName(const string& newPatientName) { patientName = newPatientName;}

    string getRecordID() const { return recordID;}

    void setRecordID(const string& newRecordID) { recordID = newRecordID;}

    string getDate() const { return date;}

    void setDate(const string& newDate) { date = newDate;}

    string getDisease() const { return disease;}

    void setDisease(const string& newDisease) { disease = newDisease;}
};

class MedicalSystem {
private:
    vector<HealthRecord> records;
    string fileName;
public:
    MedicalSystem(const string& filename);
    void welcomeScreen();
    void title();
    void mainMenu();
    void loginScreen();
    void listRecords();
    void editRecord();
    void searchRecord();
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

void MedicalSystem::welcomeScreen() {
    cout << "\n\n\n\n\n\n\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\t\t\t\t#\t\t WELCOME TO\t\t#\n";
    cout << "\t\t\t\t#          HOSPITAL RECORD SYSTEM       #\n";
    cout << "\t\t\t\t#########################################\n";
    cout << "\n\n\n\n\n Press any key to continue......\n";
    cin.get();
    system("cls");
}

void MedicalSystem::title() {
    cout << "\n\n\t\t\t--------------------------------------------------\n";
    cout << "\t\t\t\t       HOSPITAL RECORD\n";
    cout << "\t\t\t--------------------------------------------------\n";
}

void MedicalSystem::mainMenu() {
    int choice;
    do {
        system("cls");
        title();
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t1. Add Patient Record\n";
        cout << "\t\t\t\t2. List Patient Records\n";
        cout << "\t\t\t\t3. Search Patient Record\n";
        cout << "\t\t\t\t4. Edit Patient Record\n";
        cout << "\t\t\t\t5. Delete Patient Record\n";
        cout << "\t\t\t\t6. Exit\n";
        cout << "\n\n\n \n\t\t\t\tChoose from 1 to 6: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                listRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                editRecord();
                break;
            case 5:
                removeRecordByID();
                break;
            case 6:
                system("cls");
                exit(0);
            default:
                system("cls");
                cout << "\t\t\tInvalid entry. Please enter the right option :)\n";
        }
        cout << endl << "\t\t\t-------------------------" << endl;
        cout << "\t\t\tPress any key to continue." << endl;
        cin.get();
        mainMenu();
    } while (choice != 6);
}

void MedicalSystem::loginScreen() {
    int attempts = 0;
    string username, password;
    const string originalUsername = "admin";
    const string originalPassword = "12345";

    do {
        cout << "\n\n\n\n\t\t\t\tEnter your Username and Password :)\n";
        cout << "\n\n\n\t\t\t\t\tUSERNAME: ";
        cin >> username;

        cout << "\n\n\t\t\t\t\tPASSWORD: ";
        cin >> password;

        if (username == originalUsername && password == originalPassword) {
            cout << "\n\n\n\t\t\t\t\t...Login Successful...\n";
            cin.get();
            mainMenu();
            break;
        } else {
            cout << "\n\t\t\tPassword is incorrect. Try Again :)\n";
            attempts++;
            cin.get();
        }
    } while (attempts <= 2);

    if (attempts > 2) {
        cout << "You have crossed the limit. You cannot login. :(\n";
        cin.get();
        exit(0);
    }
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

void MedicalSystem::listRecords() {
    system("cls");
    title();
    cout << "Patient Records:" << endl;
    cout << "----------------------" << endl;
    if (records.empty()) {
        cout << "No records found." << endl;
    } else {
        for (const auto& record : records) {
            cout << "Record ID: " << record.getRecordID() << ", Patient ID: " << record.getPatientID()
                << ", Patient Name: " << record.getPatientName() << ", Date: " << record.getDate()
                << ", Disease: " << record.getDisease() << endl;
        }
    }
}

void MedicalSystem::editRecord() {
    system("cls");
    string searchRecordID;
    cout << "Enter record ID to edit: ";
    cin.ignore();
    getline(cin, searchRecordID);
    bool found = false;

    for (auto& record : records) {
        if (record.getRecordID() == searchRecordID) {
            found = true;

            cout << "Editing Record ID: " << record.getRecordID() << endl;
            cout << "Enter new patient ID: ";
            string newPatientID;
            getline(cin, newPatientID);
            record.setPatientID(newPatientID);

            cout << "Enter new patient name: ";
            string newPatientName;
            getline(cin, newPatientName);
            record.setPatientName(newPatientName);

            cout << "Enter new date: ";
            string newDate;
            getline(cin, newDate);
            record.setDate(newDate);

            cout << "Enter new disease: ";
            string newDisease;
            getline(cin, newDisease);
            record.setDisease(newDisease);

            cout << "Record updated successfully!" << endl;
            saveToFile(); // Update the file after editing the record
            break;
        }
    }

    if (!found) {
        cout << "No records found for the given record ID." << endl;
    }
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
    // Generate the record ID
    int nextRecordID = records.empty() ? 1 : stoi(records.back().getRecordID()) + 1;
    recordID = to_string(nextRecordID);
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

    for (auto& record : records) {
        if (record.getRecordID() == searchRecordID) {
            found = true;

            cout << "Records with record ID " << searchRecordID << ":" << endl;
            cout << "----------------------" << endl;
            cout << "Record ID: " << record.getRecordID() << ", Patient ID: " << record.getPatientID()
                 << ", Patient Name: " << record.getPatientName() << ", Date: " << record.getDate()
                 << ", Disease: " << record.getDisease() << endl;
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

    for (auto& record : records) {
        if (record.getDate() == searchDate) {
            if (!found) {
                cout << "Records with date " << searchDate << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << record.getRecordID() << ", Patient ID: " << record.getPatientID()
                 << ", Patient Name: " << record.getPatientName() << ", Date: " << record.getDate()
                 << ", Disease: " << record.getDisease() << endl;
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

    for (auto& record : records) {
        if (record.getDisease() == searchDisease) {
            if (!found) {
                cout << "Records with disease " << searchDisease << ":" << endl;
                cout << "----------------------" << endl;
                found = true;
            }
            cout << "Record ID: " << record.getRecordID() << ", Patient ID: " << record.getPatientID()
                 << ", Patient Name: " << record.getPatientName() << ", Date: " << record.getDate()
                 << ", Disease: " << record.getDisease() << endl;
        }
    }

    if (!found) {
        cout << "No records found for the given disease." << endl;
    }
}

void MedicalSystem::searchRecord() {
    system("cls");
    int choice;
    title();
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t1. Search by Record ID\n";
    cout << "\t\t\t\t2. Search by Patient ID\n";
    cout << "\t\t\t\t3. Search by Date\n";
    cout << "\t\t\t\t4. Search by Disease\n";
    cout << "\t\t\t\t5. Back to Main Menu\n";
    cout << "\n\n\n \n\t\t\t\tChoose from 1 to 5: ";
    cin >> choice;

    switch (choice) {
        case 1:
            searchByRecordID();
            break;
        case 2:
            searchByPatientID();
            break;
        case 3:
            searchByDate();
            break;
        case 4:
            searchByDisease();
            break;
        case 5:
            mainMenu();
            break;
        default:
            cout << "\t\t\tInvalid entry. Please enter the right option :)\n";
            cin.ignore();
            cin.get();
            searchRecord();
    }
}


int main() {
    MedicalSystem medicalSystem("health_records.txt");

    medicalSystem.welcomeScreen();
    medicalSystem.title();
    medicalSystem.loginScreen();
    return 0;
}
