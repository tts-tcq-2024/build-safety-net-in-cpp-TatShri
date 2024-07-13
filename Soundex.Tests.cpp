#include "Soundex.h"
#include <gtest/gtest.h>

// Test cases for generateSoundex function

TEST(GenerateSoundexTest, BasicFunctionality) {
    EXPECT_EQ(generateSoundex("Naruto"), "N630");
    EXPECT_EQ(generateSoundex("Sasuke"), "S220");
    EXPECT_EQ(generateSoundex("Luffy"), "L100");
}

TEST(GenerateSoundexTest, EmptyName) {
    EXPECT_EQ(generateSoundex(""), "");
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
    EXPECT_EQ(generateSoundex("Monkey D. Luffy"), "M524");
    EXPECT_EQ(generateSoundex("Kurosaki Ichigo"), "K621");
    EXPECT_EQ(generateSoundex("Sakura Haruno"), "S265");
}

// Add more test cases as needed

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
