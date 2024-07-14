#include "Soundex.h"
#include <gtest/gtest.h>

TEST(GenerateSoundexTest, BasicFunctionality) {
    EXPECT_EQ(generateSoundex("Naruto"), "N630");
    EXPECT_EQ(generateSoundex("Sasuke"), "S000");
    EXPECT_EQ(generateSoundex("Luffy"), "L100");
}

TEST(GenerateSoundexTest, EmptyName) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(GenerateSoundexTest, NonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("Goku123"), "G200");
    EXPECT_EQ(generateSoundex("Kakarot@"), "K263");
    EXPECT_EQ(generateSoundex("!Vegeta"), "V230");
}

TEST(GenerateSoundexTest, ShortNames) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Ai"), "A000");
    EXPECT_EQ(generateSoundex("Yu"), "Y000");
}

TEST(GenerateSoundexTest, LongNames) {
    EXPECT_EQ(generateSoundex("Monkey D. Luffy"), "M523");
    EXPECT_EQ(generateSoundex("Kurosaki Ichigo"), "K622");
    EXPECT_EQ(generateSoundex("Sakura Haruno"), "S626");
}
