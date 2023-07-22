#pragma once
#include "header.h"

string binaryToATGC(const string& binaryString)
{
    string atgcString;
    size_t length = binaryString.length();

    if (length % 2 != 0)
    {
        cerr << "Invalid binary string length. Length must be a multiple of 2." << endl;
        return atgcString;
    }

    for (size_t i = 0; i < length; i += 2)
    {
        string nucleotide;

        if (binaryString[i] == '0')
        {
            if (binaryString[i + 1] == '0')
            {
                nucleotide = "A";
            }
            else if (binaryString[i + 1] == '1')
            {
                nucleotide = "C";
            }
        }
        else if (binaryString[i] == '1')
        {
            if (binaryString[i + 1] == '0')
            {
                nucleotide = "G";
            }
            else if (binaryString[i + 1] == '1')
            {
                nucleotide = "T";
            }
        }

        if (!nucleotide.empty())
        {
            atgcString += nucleotide;
        }
        else
        {
            cerr << "Invalid binary string. Only '0' and '1' characters are allowed." << endl;
            return "";
        }
    }

    return atgcString;
}

vector<string> convertToDNA(const string& binaryStrings)
{
    vector<string> dnaString;

    size_t length = binaryStrings.length();
    size_t numPixels = length / 8;

    for (size_t i = 0; i < numPixels; ++i)
    {
        // Take a string of 8 characters each time.
        string binaryStr = binaryStrings.substr(i * 8, 8);
        // Then convert to DNA.
        string atgcString = binaryToATGC(binaryStr);
        // Store in a vector
        dnaString.push_back(atgcString);
    }
    return dnaString;
}

char xorNucleotides(char nucleotide1, char nucleotide2)
{
    if (nucleotide1 == 'A')
    {
        if (nucleotide2 == 'A')
            return 'A';
        else if (nucleotide2 == 'T')
            return 'T';
        else if (nucleotide2 == 'C')
            return 'C';
        else if (nucleotide2 == 'G')
            return 'G';
    }
    else if (nucleotide1 == 'T')
    {
        if (nucleotide2 == 'A')
            return 'T';
        else if (nucleotide2 == 'T')
            return 'A';
        else if (nucleotide2 == 'C')
            return 'G';
        else if (nucleotide2 == 'G')
            return 'C';
    }
    else if (nucleotide1 == 'C')
    {
        if (nucleotide2 == 'A')
            return 'C';
        else if (nucleotide2 == 'T')
            return 'G';
        else if (nucleotide2 == 'C')
            return 'A';
        else if (nucleotide2 == 'G')
            return 'T';
    }
    else if (nucleotide1 == 'G')
    {
        if (nucleotide2 == 'A')
            return 'G';
        else if (nucleotide2 == 'T')
            return 'C';
        else if (nucleotide2 == 'C')
            return 'T';
        else if (nucleotide2 == 'G')
            return 'A';
    }

    // Return a default value in case of an invalid nucleotide.
    cerr << "Invalid nucleotide: " << nucleotide1 << " or " << nucleotide2 << endl;
    return 'N';
}

vector<string> xorDNASequences(const vector<string>& dnaString, const string& dnaSeq2)
{
    size_t numSequences = dnaString.size();
    size_t seqLength = dnaString[0].length();

    // Check length for XOR operation.
    if (seqLength != dnaSeq2.length())
    {
        cerr << "Error: DNA sequences must have the same length for XOR operation." << endl;
        return {};
    }

    // Initialize an empty vector with the size of the original DNA vector.
    vector<string> xorResults(numSequences);

    for (size_t i = 0; i < numSequences; ++i)
    {
        const string& sequence = dnaString[i];
        string xorResult;

        for (size_t j = 0; j < seqLength; ++j)
        {
            char nucleotide1 = sequence[j];
            char nucleotide2 = dnaSeq2[j];

            char xorNucleotide = xorNucleotides(nucleotide1, nucleotide2);

            xorResult += xorNucleotide;
        }

        xorResults[i] = xorResult;
    }

    return xorResults;
}

string dnaToBinary(const vector<string>& dnaString)
{
    string linkedDNA;

    for (const string& dna : dnaString)
    {
        linkedDNA += dna;
    }

    string binaryString;

    for (const char& nucleotide : linkedDNA)
    {
        if (nucleotide == 'A')
            binaryString += "00";
        else if (nucleotide == 'C')
            binaryString += "01";
        else if (nucleotide == 'G')
            binaryString += "10";
        else if (nucleotide == 'T')
            binaryString += "11";
        else
        {
            cerr << "Invalid nucleotide: " << nucleotide << endl;
            return "";
        }
    }

    return binaryString;
}

string readBinaryStringFromFile(const string& filePath)
{
    string binaryString;

    ifstream inputFile(filePath);
    if (inputFile.is_open())
    {
        getline(inputFile, binaryString);
        inputFile.close();
        cout << "Binary string read from file: " << filePath << endl;
    }
    else
    {
        cerr << "Failed to open the input file: " << filePath << endl;
    }
    return binaryString;
}
