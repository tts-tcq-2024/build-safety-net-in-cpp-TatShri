#include "Soundex.h"
#include <cctype>
#include <string>

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    c = toupper(c);
    switch (c) {
        case 'B': case 'F': case 'P': case 'V': return '1';
        case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z': return '2';
        case 'D': case 'T': return '3';
        case 'L': return '4';
        case 'M': case 'N': return '5';
        case 'R': return '6';
        default: return '0'; // For A, E, I, O, U, H, W, Y
    }
}

// Function to capitalize the first letter of the name
std::string capitalizeFirstLetter(const std::string& name) {
    if (name.empty()) return "";
    std::string capitalized = name;
    capitalized[0] = toupper(capitalized[0]);
    return capitalized;
}

// Function to remove non-alphabetic characters from the name
std::string removeNonAlphabetic(const std::string& name) {
    std::string cleaned;
    for (char c : name) {
        if (isalpha(c)) {
            cleaned += c;
        }
    }
    return cleaned;
}

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Function to encode the name according to Soundex rules
std::string encodeName(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code == '0') continue;  // Skip vowels and other non-coding characters

        // Check if current letter encodes to the same number as the previous one
        if (code == prevCode) continue;

        // Check for 'H' or 'W' between same-coded letters
        if (i > 1 && (toupper(name[i - 1]) == 'H' || toupper(name[i - 1]) == 'W') &&
            getSoundexCode(name[i - 2]) == code) {
            continue;
        }

        soundex += code;
        prevCode = code;
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


