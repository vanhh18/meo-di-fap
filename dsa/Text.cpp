#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string binaryToATGC(const string& binaryString) {
    string atgcString;
    size_t length = binaryString.length();

    if (length % 8 != 0) {
        cerr << "Invalid binary string length. Length must be a multiple of 8." << endl;
        return atgcString;
    }

    for (size_t i = 0; i < length; i += 2) {
        string nucleotide;

        if (binaryString[i] == '0') {
            if (binaryString[i + 1] == '0') {
                nucleotide = "A";
            } else if (binaryString[i + 1] == '1') {
                nucleotide = "C";
            }
        } else if (binaryString[i] == '1') {
            if (binaryString[i + 1] == '0') {
                nucleotide = "G";
            } else if (binaryString[i + 1] == '1') {
                nucleotide = "T";
            }
        }

        if (!nucleotide.empty()) {
            atgcString += nucleotide;
        } else {
            cerr << "Invalid binary string. Only '0' and '1' characters are allowed." << endl;
            return "";
        }
    }

    return atgcString;
}

vector<string> separateByEight(const string& binaryStrings) {
    vector<string> separatedStrings;

    size_t length = binaryStrings.length();
    size_t numStrings = length / 8;

    for (size_t i = 0; i < numStrings; ++i) {
        string binaryString = binaryStrings.substr(i * 8, 8);
        string atgcString = binaryToATGC(binaryString);
        separatedStrings.push_back(atgcString);
    }

    return separatedStrings;
}

int main() {
    string filename = "Binary.txt"; // Example file name

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Failed to open the input file: " << filename << endl;
        return 1;
    }

    string binaryStrings;
    getline(inputFile, binaryStrings);

    vector<string> separatedStrings = separateByEight(binaryStrings);

    for (const auto& atgcString : separatedStrings) {
        cout << "ATGC String: " << atgcString << endl;
    }

    inputFile.close();

    return 0;
}
