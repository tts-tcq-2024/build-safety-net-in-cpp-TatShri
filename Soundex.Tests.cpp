#include "Soundex.h"
#include <gtest/gtest.h>    

TEST(GenerateSoundexTest, BasicFunctionality) {
    EXPECT_EQ(generateSoundex("Saitama"), "S350");
    EXPECT_EQ(generateSoundex("Naruto"), "N630");
    EXPECT_EQ(generateSoundex("Lelouch"), "L200");
}

TEST(GenerateSoundexTest, EmptyString) {
    EXPECT_EQ(generateSoundex(""), "0000");
}

TEST(GenerateSoundexTest, NonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("Goku123"), "G000");
    EXPECT_EQ(generateSoundex("Ryuk@DeathNote"), "R235");
}

TEST(GenerateSoundexTest, MixedCase) {
    EXPECT_EQ(generateSoundex("kAGOME"), "K500");
    EXPECT_EQ(generateSoundex("eRen yEager"), "E652");
}

TEST(GenerateSoundexTest, AllVowels) {
    EXPECT_EQ(generateSoundex("Aiueo"), "A000");
}

TEST(GenerateSoundexTest, SingleCharacterName) {
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

TEST(GenerateSoundexTest, ShortNames) {
    EXPECT_EQ(generateSoundex("Ichigo"), "I200");
    EXPECT_EQ(generateSoundex("Mio"), "M000");
}

TEST(GenerateSoundexTest, LongName) {
    EXPECT_EQ(generateSoundex("Kotobukiya"), "K312");
}

TEST(GenerateSoundexTest, NameWithHOrW) {
    EXPECT_EQ(generateSoundex("Mhnmi"), "M000");
    EXPECT_EQ(generateSoundex("Haruhi"), "H600");
}

TEST(GenerateSoundexTest, NameWithApostrophe) {
    EXPECT_EQ(generateSoundex("Itachi'Uchiha"), "I320");
}

TEST(GenerateSoundexTest, AdjacentSameCodeMerge) {
    EXPECT_EQ(generateSoundex("Aal"), "A400");
}

TEST(GenerateSoundexTest, HOrWBetweenSameCode) {
    EXPECT_EQ(generateSoundex("Sushi"), "S000");
    EXPECT_EQ(generateSoundex("Rush"), "R200");
}

TEST(GenerateSoundexTest, VowelBetweenSameCode) {
    EXPECT_EQ(generateSoundex("Taco"), "T200");
    EXPECT_EQ(generateSoundex("Ogre"), "O260");
}
