#include <iostream>
#include <cassert>
#include "Soundex.h"

void testGetSoundexCode() {
    assert(getSoundexCode('B') == '1');
    assert(getSoundexCode('F') == '1');
    assert(getSoundexCode('P') == '1');
    assert(getSoundexCode('V') == '1');
    assert(getSoundexCode('C') == '2');
    assert(getSoundexCode('G') == '2');
    assert(getSoundexCode('J') == '2');
    assert(getSoundexCode('K') == '2');
    assert(getSoundexCode('Q') == '2');
    assert(getSoundexCode('S') == '2');
    assert(getSoundexCode('X') == '2');
    assert(getSoundexCode('Z') == '2');
    assert(getSoundexCode('D') == '3');
    assert(getSoundexCode('T') == '3');
    assert(getSoundexCode('L') == '4');
    assert(getSoundexCode('M') == '5');
    assert(getSoundexCode('N') == '5');
    assert(getSoundexCode('R') == '6');
    assert(getSoundexCode('A') == '0');
    assert(getSoundexCode('E') == '0');
    assert(getSoundexCode('I') == '0');
    assert(getSoundexCode('O') == '0');
    assert(getSoundexCode('U') == '0');
    assert(getSoundexCode('H') == '0');
    assert(getSoundexCode('W') == '0');
    assert(getSoundexCode('Y') == '0');
    assert(getSoundexCode('1') == '0'); // Non-alphabetic character

    std::cout << "All getSoundexCode() tests passed!\n";
}

void testGenerateSoundex() {
    assert(generateSoundex("Washington") == "W252");
    assert(generateSoundex("Jefferson") == "J162");
    assert(generateSoundex("Adams") == "A352");
    assert(generateSoundex("Lincoln") == "L525");
    assert(generateSoundex("Madison") == "M325");
    assert(generateSoundex("Monroe") == "M650");
    assert(generateSoundex("Tyler") == "T460");
    assert(generateSoundex("Truman") == "T655");
    assert(generateSoundex("Kennedy") == "K530");
    assert(generateSoundex("Eisenhower") == "E252");

    // Edge cases
    assert(generateSoundex("") == "");
    assert(generateSoundex("A") == "A000");
    assert(generateSoundex("W") == "W000");
    assert(generateSoundex("XYZ") == "X200");

    std::cout << "All generateSoundex() tests passed!\n";
}

int main() {
    testGetSoundexCode();
    testGenerateSoundex();

    return 0;
}


