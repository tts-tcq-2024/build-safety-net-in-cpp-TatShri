#include <unordered_map>
#include <cctype>
#include <string>
#include <numeric>
#include "Soundex.h"

// Function to map characters to Soundex codes
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
    return '0'; // Default case for non-mapped characters
}

// Function to accumulate Soundex codes from name
std::string accumulateSoundexCodes(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    char prevChar = toupper(name[0]);

    for (size_t i = 1; i < name.size(); ++i) {
        char currentChar = toupper(name[i]);
        char code = getSoundexCode(currentChar);

        // Skip vowels and specific characters
        if (code == '0') {
            continue;
        }

        // Handle adjacent encoding rule
        if (code == prevCode && (prevChar != 'H' && prevChar != 'W')) {
            continue;
        }

        if (prevChar == 'H' || prevChar == 'W') {
            if (code == prevCode) {
                continue;
            }
        }

        soundex += code;
        prevCode = code;
        prevChar = currentChar;

        if (soundex.size() == 4) {
            break;
        }
    }

    return soundex;
}

// Function to pad the Soundex code to 4 characters
std::string padSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0');
    return paddedSoundex;
}

// Main function to generate Soundex code
std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex = accumulateSoundexCodes(name);
    return padSoundex(soundex);
}
