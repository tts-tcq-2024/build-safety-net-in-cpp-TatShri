#include <unordered_map>
#include <cctype>
#include <string>
#include <numeric> // Include numeric header for std::accumulate
#include "Soundex.h"

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
    return '0'; // Default case
}
// Function to accumulate Soundex codes from name
std::string accumulateSoundexCodes(const std::string& name) {
    std::string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);
    return std::accumulate(name.begin() + 1, name.end(), std::move(soundex),
        [&prevCode](std::string& acc, char c) {
            char code = getSoundexCode(c);
            if (code != '0' && code != prevCode) {
                acc += code;
                prevCode = code;
            }
            return acc;
        });
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
