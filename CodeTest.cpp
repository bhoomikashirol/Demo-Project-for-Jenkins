#include <gtest/gtest.h>
#include <string>

// Declaration of the function to be tested
std::string getHelloWorld();

// Test case for Hello World
TEST(HelloWorldTest, OutputCheck) {
    EXPECT_EQ(getHelloWorld(), "Hello World");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
