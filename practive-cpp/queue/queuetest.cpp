#include <gtest/gtest.h>
#include "queue.hpp"

TEST(EmptyTest, Empty) {
    riki::Queue<int> q{};
    EXPECT_TRUE(q.isEmpty());
    q.enqueue(3);
    EXPECT_FALSE(q.isEmpty());
}

TEST(EnqueueTest, Enqueue4Value) {
    riki::Queue<double> q{};
    q.enqueue(3.4);
    q.enqueue(5.2);
    q.enqueue(342424.4224);
    q.enqueue(-234.01);
    EXPECT_FALSE(q.isEmpty());
}

TEST(DequeueTest, Dequeue4Test) {
    riki::Queue<std::string> q{};
    q.enqueue("hieu");
    q.enqueue("tung");
    q.enqueue("tan");
    q.enqueue("nhat");
    EXPECT_EQ(q.dequeue(),"hieu");
    EXPECT_EQ(q.dequeue(),"tung");
    EXPECT_EQ(q.dequeue(),"tan");
    EXPECT_EQ(q.dequeue(),"nhat");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
