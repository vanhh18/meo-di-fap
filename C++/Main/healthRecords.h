#pragma once
#include "header.h"
#include <string.h>

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