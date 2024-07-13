#include "Soundex.h"
#include <cctype>
#include <string>

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        // A  B  C  D  E  F  G  H  I  J  K  L  M
           '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5',
        // N  O  P  Q  R  S  T  U  V  W  X  Y  Z
           '5', '0', '1', '2', '6', '2', '3', '0', '1', '0', '2', '0', '2'
    };

    if (std::isalpha(c)) {
        c = std::toupper(c);
        return soundexTable[c - 'A'];
    }
    return '0'; // For non-alphabetic characters
}

// Function to capitalize the first letter of the name
std::string capitalizeFirstLetter(const std::string& name) {
    if (name.empty()) return "";
    std::string capitalized = name;
    capitalized[0] = std::toupper(capitalized[0]);
    return capitalized;
}

// Function to remove non-alphabetic characters from the name
std::string removeNonAlphabetic(const std::string& name) {
    std::string cleaned;
    for (char c : name) {
        if (std::isalpha(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to check if the current code is the same as the previous code
bool checkForAdjacentSameCode(char currentCode, char prevCode) {
    return currentCode == prevCode;
}

// Functions to check if there is an 'H' or 'W' between same-coded letters
bool isHOrWCharacter(char c) {
    return std::toupper(c) == 'H' || std::toupper(c) == 'W';
}

// Function to check if a character is a vowel (A, E, I, O, U)
bool isVowel(char c) {
    c = std::toupper(c);
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// Function to check if there is 'H' or 'W' between same-coded letters
bool checkForHOrWBetweenSameCode(const std::string& name, size_t index, char currentCode) {
    if (index <= 1) {
        return false; // No previous character to check
    }

    char prevChar = name[index - 1];
    char prevCode = getSoundexCode(prevChar);
    char prevPrevChar = name[index - 2];

    // Check if previous character is 'H' or 'W' and if the characters have the same Soundex code
    if (isHOrWCharacter(prevChar) && prevCode == currentCode) {
        return true;
    }

    // Check if previous character was 'H' or 'W' and the character before it is a vowel (except 'Y')
    if (isHOrWCharacter(prevChar) && isVowel(prevPrevChar) && prevPrevChar != 'Y') {
        return true;
    }

    return false;
}

// Function to determine if a Soundex code should be added
bool shouldAddSoundexCode(char code, char prevCode, const std::string& name, size_t index) {
    return (code != '0' &&
            !checkForAdjacentSameCode(code, prevCode) &&
            !checkForHOrWBetweenSameCode(name, index, getSoundexCode(code)));
}

// Function to encode the name according to Soundex rules
std::string encodeName(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);

        if (shouldAddSoundexCode(code, prevCode, name, i)) {
            soundex += code;
            prevCode = code;
        }
    }
    return soundex;
}

// Function to pad the Soundex code to 4 characters
std::string padSoundexCode(const std::string& soundex) {
    std::string padded = soundex;
    while (padded.length() < 4) {
        padded += '0';
    }
    return padded;
}

// Main function to generate Soundex code for a given name
std::string generateSoundex(const std::string& name) {
    std::string cleanedName = removeNonAlphabetic(name);
    std::string capitalized = capitalizeFirstLetter(cleanedName);
    std::string encoded = encodeName(capitalized);
    return padSoundexCode(encoded);
}
