#include <gtest/gtest.h>
#include "Soundex.h"

class SoundexTest : public ::testing::Test {
protected:
    Soundex soundex;
};

TEST_F(SoundexTest, GenerateSoundex_EmptyString) {
    EXPECT_EQ(soundex.generateSoundex(""), "");
}

TEST_F(SoundexTest, GenerateSoundex_SingleCharacter) {
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("Z"), "Z000");
}

TEST_F(SoundexTest, GenerateSoundex_LongName) {
    EXPECT_EQ(soundex.generateSoundex("Qwerty"), "Q630");
    EXPECT_EQ(soundex.generateSoundex("Romanoff"), "R551");
    EXPECT_EQ(soundex.generateSoundex("Mannington"), "M552");
    EXPECT_EQ(soundex.generateSoundex("Howfcraft"), "H126");
    EXPECT_EQ(soundex.generateSoundex("Bangalore"), "B524");
    EXPECT_EQ(soundex.generateSoundex("Pierce"), "P620");
}

TEST_F(SoundexTest, GenerateSoundex_IgnoreNonAlpha) {
    EXPECT_EQ(soundex.generateSoundex("A7#&*"), "A000");
    EXPECT_EQ(soundex.generateSoundex("B1234"), "B100");
    EXPECT_EQ(soundex.generateSoundex("C$%D@!"), "C300");
}

TEST_F(SoundexTest, GenerateSoundex_MixedCases) {
    EXPECT_EQ(soundex.generateSoundex("aBcDeFgH"), "A123");
    EXPECT_EQ(soundex.generateSoundex("xyzABC"), "X212");
    EXPECT_EQ(soundex.generateSoundex("mnoPQR"), "M561");
}

TEST_F(SoundexTest, GenerateSoundex_Padding) {
    EXPECT_EQ(soundex.generateSoundex("J"), "J000");
    EXPECT_EQ(soundex.generateSoundex("Ka"), "K100");
    EXPECT_EQ(soundex.generateSoundex("LmN"), "L550");
}

