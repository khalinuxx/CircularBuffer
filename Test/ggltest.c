#include <gtest/gtest.h>

// Function to test: add
int add(int a, int b) {
    return a + b;
}

// Test case for add function
TEST(AddTest, Addition) {
    // Test with positive numbers
    ASSERT_EQ(add(2, 3), 5);
    
    // Test with negative numbers
    ASSERT_EQ(add(-2, -3), -5);
    
    // Test with zero
    ASSERT_EQ(add(0, 5), 5);
    ASSERT_EQ(add(5, 0), 5);
    ASSERT_EQ(add(0, 0), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}