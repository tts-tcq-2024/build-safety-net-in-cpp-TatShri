#include "Soundex.h"
#include <unordered_map>
#include <cctype>
#include <string>

// Character mapping function
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

// Function to handle character skipping and duplicate removal
void handleSoundexCharacter(std::string& soundex, char prevCode, char code, char currentChar) {
    if (code != '0' && (code != prevCode || currentChar == 'h' || currentChar == 'w')) {
        soundex += code;
        prevCode = code;
    }
}

// Function to accumulate Soundex codes from name
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

// Function to pad the Soundex code to 4 characters
std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    if (paddedSoundex.size() < 4) {
        paddedSoundex.resize(4, '0');
    } else if (paddedSoundex.size() > 4) {
        paddedSoundex = paddedSoundex.substr(0, 4);
    }
    return paddedSoundex;
}

// Main function to generate Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";
    std::string soundex = accumulateSoundexCodes(name);
    return padSoundex(soundex);
}
