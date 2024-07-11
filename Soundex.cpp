#include <vector>
#include <cctype>
#include <string>

static const std::vector<std::pair<char, char>> soundexMap {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'},
    {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

char mapCharToSoundex(char c, const std::vector<std::pair<char, char>>& soundexMap) {
    c = std::toupper(c);
    for (const auto& pair : soundexMap) {
        if (pair.first == c) {
            return pair.second;
        }
    }
    return '0';
}

bool canAppend(char code, char prevCode, char currentChar) {
    if (currentChar == 'h' || currentChar == 'w') {
        return true;
    }
    return isSoundexDifferent(code, prevCode);
}

bool isSoundexDifferent(char code, char prevCode) {
    return (code != '0' && code != prevCode);
}

void appendSoundexCode(std::string& soundex, char code, char& prevCode, char currentChar) {
    if (canAppend(code, prevCode, currentChar)) {
        soundex += code;
        prevCode = code;
    }
}

std::string computeSoundexCodes(const std::string& name, const std::vector<std::pair<char, char>>& soundexMap) {
    std::string soundex(1, std::toupper(name[0]));
    char prevCode = mapCharToSoundex(name[0], soundexMap);

    for (std::size_t i = 1; i < name.size(); ++i) {
        char c = name[i];
        char code = mapCharToSoundex(c, soundexMap);
        appendSoundexCode(soundex, code, prevCode, c);
    }

    return soundex;
}

std::string formatSoundex(const std::string& soundex) {
    return soundex.size() < 4 ? soundex + std::string(4 - soundex.size(), '0') : soundex;
}

std::string generateSoundex(const std::string& name, const std::vector<std::pair<char, char>>& soundexMap) {
    if (name.empty()) return "";
    std::string soundex = computeSoundexCodes(name, soundexMap);
    return formatSoundex(soundex);
}

int main() {
    std::string name = "Example";
    std::string soundexCode = generateSoundex(name, soundexMap);
    // Output or use the soundexCode as needed
}
