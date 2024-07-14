#include "Soundex.h"
#include <gtest/gtest.h>    

TEST_F(GenerateSoundexTest, BasicFunctionality) {
    EXPECT_EQ(generateSoundex("Saitama"), "S350");
    EXPECT_EQ(generateSoundex("Naruto"), "N630");
    EXPECT_EQ(generateSoundex("Lelouch"), "L200");
}

TEST_F(GenerateSoundexTest, EmptyString) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST_F(GenerateSoundexTest, NonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("Goku123"), "G000");
    EXPECT_EQ(generateSoundex("Ryuk@DeathNote"), "R235");
}

TEST_F(GenerateSoundexTest, MixedCase) {
    EXPECT_EQ(generateSoundex("kAGOME"), "K500");
    EXPECT_EQ(generateSoundex("eRen yEager"), "E652");
}

TEST_F(GenerateSoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aiueo"), "A000");
}

TEST_F(GenerateSoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

TEST_F(GenerateSoundexTest, ShortNames) {
    EXPECT_EQ(generateSoundex("Ichigo"), "I200");
    EXPECT_EQ(generateSoundex("Mio"), "M000");
}

TEST_F(GenerateSoundexTest, LongName) {
    EXPECT_EQ(generateSoundex("Kotobukiya"), "K312");
}

TEST_F(GenerateSoundexTest, NameWithHOrW) {
    EXPECT_EQ(generateSoundex("Mhnmi"), "M200");
    EXPECT_EQ(generateSoundex("Haruhi"), "H600");
}

TEST_F(GenerateSoundexTest, NameWithApostrophe) {
    EXPECT_EQ(generateSoundex("Itachi'Uchiha"), "I320");
}
