#include "picotest.hpp"

TEST(Case1, Test1) {
    EXPECT_EQ(0, 0);
}
TEST(Case2, Test1) {
    EXPECT_EQ(0, 0);
}
TEST(Case3, Test1) {
    EXPECT_EQ(0, 0);
}
TEST(Case4, Test1) {
    EXPECT_NEAR(0, 0, 0.1);
}
TEST(Case4, Test2) {
    EXPECT_NEAR(0, 0, 0.1);
}
TEST(Case4, Test3) {
    EXPECT_NEAR(0, 0, 0.1);
}

int main(int argc, char **argv) {
    return RUN_ALL_TESTS();
}

