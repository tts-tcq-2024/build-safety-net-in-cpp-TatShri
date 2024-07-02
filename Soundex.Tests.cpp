#include <gtest/gtest.h>
#include "Soundex.h"

// Test getSoundexCode function
TEST(GetSoundexCodeTest, BasicMappings) {
    EXPECT_EQ(getSoundexCode('B'), '1');
    EXPECT_EQ(getSoundexCode('F'), '1');
    EXPECT_EQ(getSoundexCode('P'), '1');
    EXPECT_EQ(getSoundexCode('V'), '1');
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('G'), '2');
    EXPECT_EQ(getSoundexCode('J'), '2');
    EXPECT_EQ(getSoundexCode('K'), '2');
    EXPECT_EQ(getSoundexCode('Q'), '2');
    EXPECT_EQ(getSoundexCode('S'), '2');
    EXPECT_EQ(getSoundexCode('X'), '2');
    EXPECT_EQ(getSoundexCode('Z'), '2');
    EXPECT_EQ(getSoundexCode('D'), '3');
    EXPECT_EQ(getSoundexCode('T'), '3');
    EXPECT_EQ(getSoundexCode('L'), '4');
    EXPECT_EQ(getSoundexCode('M'), '5');
    EXPECT_EQ(getSoundexCode('N'), '5');
    EXPECT_EQ(getSoundexCode('R'), '6');
    EXPECT_EQ(getSoundexCode('A'), '0');
    EXPECT_EQ(getSoundexCode('E'), '0');
    EXPECT_EQ(getSoundexCode('I'), '0');
    EXPECT_EQ(getSoundexCode('O'), '0');
    EXPECT_EQ(getSoundexCode('U'), '0');
    EXPECT_EQ(getSoundexCode('H'), '0');
    EXPECT_EQ(getSoundexCode('W'), '0');
    EXPECT_EQ(getSoundexCode('Y'), '0');
    EXPECT_EQ(getSoundexCode('1'), '0'); // Non-alphabetic character
}

// Test generateSoundex function
TEST(GenerateSoundexTest, BasicNames) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");
    EXPECT_EQ(generateSoundex("Jefferson"), "J162");
    EXPECT_EQ(generateSoundex("Adams"), "A352");
    EXPECT_EQ(generateSoundex("Lincoln"), "L525");
    EXPECT_EQ(generateSoundex("Madison"), "M325");
    EXPECT_EQ(generateSoundex("Monroe"), "M650");
    EXPECT_EQ(generateSoundex("Tyler"), "T460");
    EXPECT_EQ(generateSoundex("Truman"), "T655");
    EXPECT_EQ(generateSoundex("Kennedy"), "K530");
    EXPECT_EQ(generateSoundex("Eisenhower"), "E252");

    // Edge cases
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("W"), "W000");
    EXPECT_EQ(generateSoundex("XYZ"), "X200");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
