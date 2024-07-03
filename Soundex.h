#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

std::string generateSoundex(const std::string& name);
char getSoundexCode(char c);
std::string accumulateSoundexCodes(const std::string& name);
std::string padSoundex(const std::string& soundex);

#endif // SOUNDEX_H
