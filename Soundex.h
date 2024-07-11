#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>
#include <vector>

// Public function for generating Soundex code
std::string generateSoundex(const std::string& name, const std::vector<std::pair<char, char>>& soundexMap);

#endif // SOUNDEX_H
