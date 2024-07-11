#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <vector>

class Soundex {
public:
    Soundex();

    std::string generateSoundex(const std::string& name) const;

private:
    std::unordered_map<char, char> soundexMap;

    char mapCharToSoundex(char c) const;
    bool isSeparator(char currentChar) const;
    void appendValidSoundexCode(std::string& soundex, char code, char& prevCode, char currentChar) const;
};

#endif // SOUNDEX_H
