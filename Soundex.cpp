#include "Soundex.h"
#include <cctype>
#include <string>

// Function to get the Soundex code for a given character
char createandFetchSoundexcode(char c) {
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

bool isHOrWCharacter(char c) {
    char check = std::toupper(c);
    return check == 'H' || check == 'W';
}

// Function to check if the previous character is H or W
bool isPreviousCharHOrW(const std::string& name, size_t index) {
    if (index > 0) {
        return isHOrWCharacter(name[index - 1]);
    }
    return false;
}

// Function to check if the previous character is H or W and the character before that has the same Soundex code as the current code
bool isPrevPrevCharSameCode(const std::string& name, size_t index, char currentCode) {
    if (index > 1) {
        return createandFetchSoundexcode(name[index - 2]) == currentCode;
    }
    return false;
}

// Function to check if there is an H or W character between two characters with the same Soundex code
bool checkForHOrWBetweenSameCode(const std::string& name, size_t index, char currentCode) {
    return isPreviousCharHOrW(name, index) && isPrevPrevCharSameCode(name, index, currentCode);
}

// Function to determine if a Soundex code should be added
bool shouldAddSoundexCode(char code, char prevCode, const std::string& name, size_t index) {
    return (code != '0' &&
            !checkForAdjacentSameCode(code, prevCode) &&
            !checkForHOrWBetweenSameCode(name, index, code));
}

// Function to validate and potentially add the Soundex code
void validateSoundexCode(const std::string& name, size_t index, std::string& soundex, char& prevCode) {
    char code = createandFetchSoundexcode(name[index]);

    if (shouldAddSoundexCode(code, prevCode, name, index)) {
        soundex += code;
        prevCode = code;
    }
}

// Function to check the Soundex length and call validateSoundexCode if necessary
void checkSoundexLength(const std::string& name, char c, std::string& soundex, char& prevCode) {
    if (soundex.length() < 4) {
        size_t index = &c - &name[0];
        validateSoundexCode(name, index, soundex, prevCode);
    }
}

// Function to encode the name according to Soundex rules using std::accumulate
std::string encodeName(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = createandFetchSoundexcode(name[0]);

    std::accumulate(name.begin() + 1, name.end(), prevCode,
        [&soundex, &name](char prevCode, char c) {
            checkSoundexLength(name, c, soundex, prevCode);
            return prevCode;
        });
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
