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

TEST_F(SoundexTest, EmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST_F(SoundexTest, SingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

TEST_F(SoundexTest, BasicNames) {
    EXPECT_EQ(generateSoundex("Smith"), "S530");
    EXPECT_EQ(generateSoundex("Johnson"), "J525");
    EXPECT_EQ(generateSoundex("Williams"), "W452");
}

TEST_F(SoundexTest, IgnoreNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("Jo hn-son"), "J525");
    EXPECT_EQ(generateSoundex("O'Conner"), "O256");
}

TEST_F(SoundexTest, MultipleConsecutiveLettersMappedToSameDigit) {
    EXPECT_EQ(generateSoundex("Zuckerberg"), "Z261");
}

TEST_F(SoundexTest, NameWithSameAdjacentLetters) {
    EXPECT_EQ(generateSoundex("Lee"), "L000");
}

TEST_F(SoundexTest, NameWithLessThanFourDistinctCodes) {
    EXPECT_EQ(generateSoundex("Wang"), "W520");
}

TEST_F(SoundexTest, NameWithMoreThanFourDistinctCodes) {
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

// Add more test cases as needed to cover additional scenarios

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
