#include "gtest/gtest.h"
#include "../bitlib/bit_operations.h"

TEST(BitOperationsTest, ChangeLastThreeBitsToOnesFromRight) {
    unsigned int number = 0b101010;
    changeLastThreeBitsToOnesFromRight(&number);
    EXPECT_EQ(number, 0b101111);
}

TEST(BitOperationsTest, ChangeLastThreeBitsToOnesFromLeft) {
    unsigned int number = 0b1010101010;
    changeLastThreeBitsToOnesFromLeft(&number);
    EXPECT_EQ(number, 0b1010101110);
}

TEST(BitOperationsTest, MultiplyUsingBitwise) {
    unsigned int number = 10;
    multiplyUsingBitwise(&number);
    EXPECT_EQ(number, 10 << SHIFT_BY_SIX);
}

TEST(BitOperationsTest, DivideUsingBitwise) {
    unsigned int number = 100;
    divideUsingBitwise(&number);
    EXPECT_EQ(number, 100 >> SHIFT_BY_SIX);
}

TEST(BitOperationsTest, ChangeNthBitToOne) {
    unsigned int number = 0b101010;
    int n = 2; // Changing the 2nd bit (0-based indexing)
    changeNthBitToOne(&number, n);
    EXPECT_EQ(number, 0b101110);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
