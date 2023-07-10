#pragma once

#include <string>
#include <vector>

std::string binaryToATGC(const std::string& binaryString);
std::vector<std::string> convertToDNA(const std::string& binaryStrings);
std::string xorDNASequences(const std::vector<std::string>& dnaString, const std::string& dnaSeq2);
