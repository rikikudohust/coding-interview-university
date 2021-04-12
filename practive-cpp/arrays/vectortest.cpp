#include <gtest/gtest.h>
#include "jvector.hpp"

TEST(SizeTest, EmptySize) {
    riki::JVector<int> jvector{};
    int size = jvector.size();
    EXPECT_EQ(size,0);
}

TEST(SizeTest, Size1to2) {
    riki::JVector<int> jvector{};
    jvector.push(1);
    EXPECT_EQ(1,jvector.size());
    jvector.push(2);
    EXPECT_EQ(2,jvector.size());
}

TEST (EmptyTest, Emptyto1) {
    riki::JVector<int> jvector{};
    EXPECT_EQ(true,jvector.isEmpty());
    jvector.push(1);
    EXPECT_EQ(false,jvector.isEmpty());
}

TEST (CapacityTest, Default) {
    riki::JVector<int> jvector{};
    EXPECT_EQ(16,jvector.capacity());
}

TEST (CapacityTest, NotDefault) {
    riki::JVector<int> jvector(20);
    EXPECT_EQ(64, jvector.capacity());
}

TEST (ValueTest, InsertAt3) {
    riki::JVector<int> jvector{};
    for (int i = 0; i < 5; ++i) {
        jvector.push(i);
    }
    jvector.insert(2,10);
    EXPECT_EQ(10,jvector.at(2));
}

TEST (ValueTest,PopTest) {
    riki::JVector<int> jvector{};
    for (int i = 0; i < 5; ++i) {
        jvector.push(i);
    }
    jvector.pop();
    EXPECT_EQ(4,jvector.size());
}

TEST (ValueTest, DelTest) {
    riki::JVector<int> jvector{};
    for (int i = 0; i < 5; ++i) {
        jvector.push(i);
    }
    jvector.del(1);
    EXPECT_NE(1,jvector.at(1));
}

TEST (ValueTest, RemoveTest) {
    riki::JVector<int> jvector{};
    jvector.push(1);
    for (int i = 0; i < 5; ++i) {
        jvector.push(i);
    }
    jvector.remove(1);
    EXPECT_EQ(-1,jvector.find(1));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
