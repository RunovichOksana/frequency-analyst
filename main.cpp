#include "header.h"


int main() {
    int32_t frequency[26];
    int32_t totalLetters;

    initializeFrequency(frequency, totalLetters);

    int32_t choice = getUserChoice();

    if (choice == 1) {
        std::string text = getTextInput();
        analyzeText(text, frequency, totalLetters);
    } else if (choice == 2) {
        std::string filename = getFilename();

        if (!readFromFile(filename, frequency, totalLetters)) {
            std::cout << "Error with opening file!" << filename << '\n';
            return 1;
        }
    } else {
        std::cout << "Mistake with choise!" << '\n';
        return 1;
    }

    printStatistics(frequency, totalLetters);
    return 0;
}

