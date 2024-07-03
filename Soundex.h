#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <unordered_map>
#include <cctype>
#include <string>
#include <numeric>

char getSoundexCode(char c);
std::string accumulateSoundexCodes(const std::string& name);
std::string padSoundex(const std::string& soundex);
std::string generateSoundex(const std::string& name);

