#include "binarySearch.hpp"
#include <gtest/gtest.h>

TEST(binarySearchTest, 5number) {
    std::vector<int> a = {1,2,3,4,5};
    EXPECT_EQ(-1,binarySearch(a,7));
    EXPECT_EQ(3,binarySearch(a,4));
}
TEST(binarySearchRecurTest, 7number) {
    std::vector<int> a = {1,3,5,66,72,105,201};
    EXPECT_EQ(-1,binarySearchRecur(a,0,6,2));
    EXPECT_EQ(2,binarySearchRecur(a,0,6,5));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

