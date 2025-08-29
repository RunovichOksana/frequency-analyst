#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdint>
#include <string>

void initializeFrequency(int32_t* frequency, int32_t& totalLetters);
void analyzeText(const std::string& text, int32_t* frequency, int32_t& totalLetters);
bool readFromFile(const std::string& filename, int32_t* frequency, int32_t& totalLetters);
void printStatistics(const int32_t* frequency, int32_t totalLetters);
int32_t getUserChoice();
std::string getTextInput();
std::string getFilename();
 