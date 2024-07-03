#include <gtest/gtest.h>
#include "Soundex.h"  // Include your header file where functions are declared

// Test fixture for Soundex related tests
class SoundexTest : public ::testing::Test {
protected:
    // Optionally, you can add setup code if needed
    void SetUp() override {}

    // Optionally, add teardown code if needed
    void TearDown() override {}
};

// Test getSoundexCode function
TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(getSoundexCode('A'), '0');
    EXPECT_EQ(getSoundexCode('B'), '1');
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('D'), '3');
    EXPECT_EQ(getSoundexCode('L'), '4');
    EXPECT_EQ(getSoundexCode('M'), '5');
    EXPECT_EQ(getSoundexCode('R'), '6');
    EXPECT_EQ(getSoundexCode('Z'), '2');
    EXPECT_EQ(getSoundexCode('b'), '1'); // Lowercase input
    EXPECT_EQ(getSoundexCode('@'), '0'); // Non-alphabetic character
}

// Test accumulateSoundexCodes function
TEST(SoundexTest, AccumulateSoundexCodes) {
    EXPECT_EQ(accumulateSoundexCodes("Robert"), "R163");
    EXPECT_EQ(accumulateSoundexCodes("Rupert"), "R163");
    EXPECT_EQ(accumulateSoundexCodes("Rubin"), "R150");
    EXPECT_EQ(accumulateSoundexCodes("Ashcraft"), "A2613");
    EXPECT_EQ(accumulateSoundexCodes("Tymczak"), "T5232");
    EXPECT_EQ(accumulateSoundexCodes("Pfister"), "P1236");
    EXPECT_EQ(accumulateSoundexCodes("Honeyman"), "H5535");
}

// Test padSoundex function
TEST(SoundexTest, PadSoundex) {
    EXPECT_EQ(padSoundex("R1"), "R100");
    EXPECT_EQ(padSoundex("R16"), "R160");
    EXPECT_EQ(padSoundex("R163"), "R163");
    EXPECT_EQ(padSoundex("R1635"), "R1635"); // Longer string remains unchanged
}

// Test generateSoundex function
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T523");
    EXPECT_EQ(generateSoundex("Pfister"), "P123");
    EXPECT_EQ(generateSoundex("Honeyman"), "H553");
    EXPECT_EQ(generateSoundex(""), ""); // Empty string input
}

// Main function for runnin

