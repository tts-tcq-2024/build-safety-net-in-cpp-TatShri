#include "Soundex.h"
#include <gtest/gtest.h>

using namespace std;

// Test fixture for Soundex functions
class SoundexTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Tests for getSoundexCode function

// Test valid characters and their mappings
TEST_F(GetSoundexCodeTest, ValidCharacters) {
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
}

// Test default case (other characters)
TEST_F(GetSoundexCodeTest, DefaultCase) {
    // Test characters that are not mapped explicitly
    EXPECT_EQ(getSoundexCode('A'), '0'); // A should map to '0'
    EXPECT_EQ(getSoundexCode('E'), '0'); // E should map to '0'
    EXPECT_EQ(getSoundexCode('I'), '0'); // I should map to '0'
    EXPECT_EQ(getSoundexCode('O'), '0'); // O should map to '0'
    EXPECT_EQ(getSoundexCode('U'), '0'); // U should map to '0'
    EXPECT_EQ(getSoundexCode('H'), '0'); // H should map to '0'
    EXPECT_EQ(getSoundexCode('W'), '0'); // W should map to '0'
    EXPECT_EQ(getSoundexCode('Y'), '0'); // Y should map to '0'
}

// Test edge cases

// Test lowercase characters
TEST_F(GetSoundexCodeTest, LowercaseCharacters) {
    EXPECT_EQ(getSoundexCode('b'), '1');
    EXPECT_EQ(getSoundexCode('c'), '2');
    EXPECT_EQ(getSoundexCode('d'), '3');
    EXPECT_EQ(getSoundexCode('l'), '4');
    EXPECT_EQ(getSoundexCode('m'), '5');
    EXPECT_EQ(getSoundexCode('r'), '6');
}

// Test non-alphabetic characters
TEST_F(GetSoundexCodeTest, NonAlphabeticCharacters) {
    EXPECT_EQ(getSoundexCode('1'), '0'); // Numeric character should map to '0'
    EXPECT_EQ(getSoundexCode('@'), '0'); // Special character should map to '0'
}


// Tests for accumulateSoundexCodes function
TEST(AccumulateSoundexCodesTest, BasicName) {
    EXPECT_EQ(accumulateSoundexCodes("Rubin"), "R15");
}

TEST(AccumulateSoundexCodesTest, NameWithHAndW) {
    EXPECT_EQ(accumulateSoundexCodes("Tymczak"), "T52");
}

TEST(AccumulateSoundexCodesTest, NameWithAdjacentSameCodes) {
    EXPECT_EQ(accumulateSoundexCodes("Pfister"), "P236");
}

TEST(AccumulateSoundexCodesTest, NameWithExcludedCharacters) {
    EXPECT_EQ(accumulateSoundexCodes("Honeyman"), "H5");
}

TEST(AccumulateSoundexCodesTest, EmptyName) {
    EXPECT_EQ(accumulateSoundexCodes(""), "0000");
}

// Tests for padSoundex function
TEST(PadSoundexTest, NormalSoundex) {
    EXPECT_EQ(padSoundex("R163"), "R163");
}

TEST(PadSoundexTest, ShortSoundex) {
    EXPECT_EQ(padSoundex("T52"), "T520");
}

TEST(PadSoundexTest, FullSoundex) {
    EXPECT_EQ(padSoundex("P236"), "P236");
}

TEST(PadSoundexTest, EmptySoundex) {
    EXPECT_EQ(padSoundex(""), "0000");
}

// Tests for generateSoundex function
TEST(GenerateSoundexTest, NormalName) {
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(GenerateSoundexTest, NameWithHAndW) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T520");
}

TEST(GenerateSoundexTest, NameWithAdjacentSameCodes) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

TEST(GenerateSoundexTest, NameWithExcludedCharacters) {
    EXPECT_EQ(generateSoundex("Honeyman"), "H500");
}

TEST(GenerateSoundexTest, EmptyName) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Run the tests
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
