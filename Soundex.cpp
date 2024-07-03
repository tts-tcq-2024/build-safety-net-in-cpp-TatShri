#include "Soundex.h"
#include <unordered_map>
#include <cctype>

char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'},
        {'L', '4'},
        {'M', '5'}, {'N', '5'},
        {'R', '6'}
    };
    c = std::toupper(c);
    auto it = soundexMap.find(c);
    if (it != soundexMap.end()) {
        return it->second;
    }
    return '0'; // Default case for vowels and other excluded characters
}

// Function to determine if a character is a vowel or excluded character
bool isVowelOrExcluded(char c) {
    static const std::string vowelsAndExcluded = "AEIOUYHW";
    return vowelsAndExcluded.find(std::toupper(c)) != std::string::npos;
}

// Function to determine if a character should be appended based on rules
bool shouldAppend(char code, char prevCode, char currentChar) {
    return (code != '0' && code != prevCode) || (currentChar == 'h') || (currentChar == 'w');
}

// Main function to handle encoding of Soundex character
void handleSoundexCharacter(std::string& soundex, char& prevCode, char code, char currentChar) {
    if (!isVowelOrExcluded(currentChar) && shouldAppend(code, prevCode, currentChar)) {
        soundex += code;
        prevCode = code;
    }
}

std::string accumulateSoundexCodes(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getSoundexCode(name[i]);
        handleSoundexCharacter(soundex, prevCode, code, name[i]);
    }

    return soundex;
}

std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    if (paddedSoundex.size() < 4) {
        paddedSoundex.resize(4, '0');
    } else if (paddedSoundex.size() > 4) {
        paddedSoundex = paddedSoundex.substr(0, 4);
    }
    return paddedSoundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex = accumulateSoundexCodes(name);
    return padSoundex(soundex);
}
