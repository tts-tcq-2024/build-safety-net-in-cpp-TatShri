#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
#include "Soundex.h"


Soundex::Soundex() : soundexMap {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
    {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
} {}

char Soundex::mapCharToSoundex(char c) const {
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0'; // Default case for unknown characters
}

bool Soundex::isSeparator(char currentChar) const {
    return std::isalpha(currentChar) && (currentChar == 'H' || currentChar == 'W');
}

void Soundex::appendValidSoundexCode(std::string& soundex, char code, char& prevCode, char currentChar) const {
    if (code != '0') {
        if (std::isalpha(currentChar) && !isSeparator(currentChar)) { // Check if currentChar is a vowel
            if (code == prevCode) {
                soundex += code; // Append code twice for vowels
            } else {
                soundex += code; // Append code once
                prevCode = code;
            }
        } else {
            soundex += code; // Append code once
            prevCode = code;
        }
    }
}

std::string Soundex::generateSoundex(const std::string& name) const {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = mapCharToSoundex(name[0]);

    for (size_t i = 1; i < name.size() && soundex.size() < 4; ++i) {
        char c = std::tolower(name[i]);
        char code = mapCharToSoundex(c);
        appendValidSoundexCode(soundex, code, prevCode, name[i]);
    }

    soundex.resize(4, '0'); // Pad with zeros if necessary

    return soundex;
}

