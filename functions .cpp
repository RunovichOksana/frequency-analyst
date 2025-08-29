#include "header.h"

void initializeFrequency(int32_t* frequency, int32_t& totalLetters) {
    totalLetters = 0;
    for (int32_t i = 0; i < 26; ++i) {
        frequency[i] = 0;
    }
}

void analyzeText(const std::string& text, int32_t* frequency, int32_t& totalLetters) {
    for (int32_t i = 0; i < static_cast<int32_t>(text.length()); ++i) {
        char c = static_cast<char>(std::tolower(text[i]));
        if (c >= 'a' && c <= 'z') {
            ++frequency[static_cast<int32_t>(c - 'a')];
            ++totalLetters;
        }
    }
}

bool readFromFile(const std::string& filename, int32_t* frequency, int32_t& totalLetters) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        analyzeText(line, frequency, totalLetters);
    }
    file.close();
    return true;
}

void printStatistics(const int32_t* frequency, int32_t totalLetters) {
    std::cout << "Letter frequency analysis:\n";
    std::cout << "Letter | Quantity | Frequency (%)\n";
    std::cout << "------|------------|------------\n";

    for (int32_t i = 0; i < 26; ++i) {
        char letter = static_cast<char>('A' + i);
        double percentage = totalLetters > 0 ? 
            static_cast<double>(frequency[i]) / static_cast<double>(totalLetters) * 100.0 : 0.0;

        std::cout << std::setw(5) << letter << " | " 
                 << std::setw(10) << frequency[i] << " | " 
                 << std::setw(8) << std::fixed << std::setprecision(2) 
                 << percentage << "%\n";
    }
    std::cout << "\nTotal letters: " << totalLetters << '\n';
}

int32_t getUserChoice() {
    int32_t choice;
    std::cout << "Select the text source:\n";
    std::cout << "1 - Enter text\n";
    std::cout << "2 - Load from file\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    return choice;
}

std::string getTextInput() {
    std::string text;
    std::cout << "Input text: ";
    std::getline(std::cin, text);
    return text;
}

std::string getFilename() {
    std::string filename;
    std::cout << "Input filename: ";
    std::getline(std::cin, filename);
    return filename;
}