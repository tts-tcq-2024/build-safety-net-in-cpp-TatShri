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

// Test cases

TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(getSoundexCode('B'), '1');
    EXPECT_EQ(getSoundexCode('F'), '1');
    EXPECT_EQ(getSoundexCode('C'), '2');
    EXPECT_EQ(getSoundexCode('D'), '3');
    EXPECT_EQ(getSoundexCode('L'), '4');
    EXPECT_EQ(getSoundexCode('M'), '5');
    EXPECT_EQ(getSoundexCode('R'), '6');
    EXPECT_EQ(getSoundexCode('A'), '0');
    EXPECT_EQ(getSoundexCode('H'), '0');
    EXPECT_EQ(getSoundexCode('W'), '0');
    EXPECT_EQ(getSoundexCode('b'), '1'); // Lowercase
    EXPECT_EQ(getSoundexCode('f'), '1'); // Lowercase
}

// Test accumulateSoundexCodes function
TEST(SoundexTest, AccumulateSoundexCodes) {
    EXPECT_EQ(accumulateSoundexCodes("Robert"), "R163");
    EXPECT_EQ(accumulateSoundexCodes("Rupert"), "R163");
    EXPECT_EQ(accumulateSoundexCodes("Ashcraft"), "A2613");
    EXPECT_EQ(accumulateSoundexCodes("Tymczak"), "T522");
    EXPECT_EQ(accumulateSoundexCodes("Pfister"), "P1236");
    EXPECT_EQ(accumulateSoundexCodes("Honeyman"), "H555");
}

// Test padSoundex function
TEST(SoundexTest, PadSoundex) {
    EXPECT_EQ(padSoundex("R1"), "R100");
    EXPECT_EQ(padSoundex("R12"), "R120");
    EXPECT_EQ(padSoundex("R123"), "R123");
    EXPECT_EQ(padSoundex("R1234"), "R123");
}

// Test generateSoundex function
TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Ashcraft"), "A261");
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
    EXPECT_EQ(generateSoundex("Pfister"), "P123");
    EXPECT_EQ(generateSoundex("Honeyman"), "H555");
    EXPECT_EQ(generateSoundex(""), "");
}

// Add more test cases as needed to cover additional scenarios

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
