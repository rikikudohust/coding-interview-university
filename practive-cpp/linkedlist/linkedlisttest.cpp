#include <gtest/gtest.h>
#include "linkedlist.hpp"

TEST(sizeTest, sizeEmpty) {
  riki::LinkedList<int> list{};
  int size = list.size();

  EXPECT_EQ(size, 0);
}

TEST(sizeTest, size1to2) {
  riki::LinkedList<int> list{};
  list.push_front(4);

  EXPECT_EQ(list.size(), 1);

  list.push_front(9);
  EXPECT_EQ(list.size(), 2);
}

TEST(sizeTest, size3) {
  riki::LinkedList<int> list{};
  list.push_front(4);
  list.push_front(9);
  list.push_front(13);
  EXPECT_EQ(list.size(), 3);
}

TEST(EmptyTest, Empty) {
  riki::LinkedList<std::string> list{};

  EXPECT_TRUE(list.isEmpty());
  list.push_front("word");

  EXPECT_FALSE(list.isEmpty());
}
// Kiem tra gia tri o vi tri thu index

TEST(value_atTest, Value012) {
  riki::LinkedList<int> list{};

  list.push_front(99);
  EXPECT_EQ(list.value_at(0), 99);

  list.push_front(3);
  list.push_front(122);
  EXPECT_EQ(list.value_at(0), 122);
  EXPECT_EQ(list.value_at(1), 3);
  EXPECT_EQ(list.value_at(2), 99);
}
// kiem tra ham Pop front
TEST(PopfrontTest, Pop1) {
  riki::LinkedList<int> list{};

  list.push_front(66);
  int val = list.pop_front();

  EXPECT_EQ(val, 66);
}

TEST(PopfrontTest, Pop2) {
  riki::LinkedList<int> list{};

  list.push_front(12);
  list.push_front(11);

  EXPECT_EQ(list.pop_front(), 11);
  EXPECT_EQ(list.pop_front(), 12);
}
// Push back test
TEST(push_backTest, PushEmpty) {
  riki::LinkedList<int> list{};

  list.push_back(4);
  EXPECT_EQ(list.size(), 1);
}

TEST(push_backTest, PushNonEmpty) {
  riki::LinkedList<int> list{};

  list.push_back(123);
  list.push_back(456);

  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.value_at(0), 123);
  EXPECT_EQ(list.value_at(1), 456);
}
// Pop back Test
TEST(pop_backTest, Pop1) {
  riki::LinkedList<int> list{};

  list.push_back(4);
  int val = list.pop_back();

  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(val, 4);
}

TEST(pop_backTest, Pop2) {
  riki::LinkedList<int> list{};

  list.push_back(33);
  list.push_back(36);
  EXPECT_EQ(list.pop_back(), 36);
  EXPECT_EQ(list.pop_back(), 33);
  EXPECT_EQ(list.size(), 0);
}
// front test
TEST(frontTest, front1) {
  riki::LinkedList<int> list{};

  list.push_front(123);
  EXPECT_EQ(list.front(), 123);
}

TEST(frontTest, front2) {
  riki::LinkedList<int> list{};

  list.push_front(123);
  list.push_front(456);
  EXPECT_EQ(list.front(), 456);
}
// back test
TEST(backTest, back1) {
  riki::LinkedList<int> list{};

  list.push_back(3);
  EXPECT_EQ(list.back(), 3);
}

TEST(backTest, back2) {
  riki::LinkedList<int> list{};

  list.push_back(123);
  list.push_back(456);
  EXPECT_EQ(list.back(), 456);
}
//insert
TEST(insertTest, insertfrontEmpty) {
  riki::LinkedList<int> list{};

  list.insert(0, 3);

  EXPECT_EQ(list.front(), 3);
}

TEST(insertTest, insertfrontNonEmpty) {
  riki::LinkedList<int> list{};

  list.push_front(123);
  list.insert(0, 3);

  EXPECT_EQ(list.front(), 3);
  EXPECT_EQ(list.back(), 123);
}

TEST(insertTest, insertback) {
  riki::LinkedList<int> list{};

  list.push_back(123);
  list.insert(1, 3);

  EXPECT_EQ(list.back(), 3);
}

TEST(insertTest, insertMid) {
  riki::LinkedList<int> list{};

  list.push_back(123);
  list.push_back(456);
  list.push_back(999);
  list.insert(2, 777);

  EXPECT_EQ(list.value_at(1), 456);
  EXPECT_EQ(list.value_at(2), 777);
  EXPECT_EQ(list.back(), 999);
}

//erase
TEST(eraseTest, eraseOnly) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.erase(0);

  EXPECT_EQ(list.size(), 0);
}

TEST(eraseTest, eraseFirst) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.push_back(55);
  list.erase(0);

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 55);
}

TEST(eraseTest, eraseLast) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.push_back(55);
  list.erase(1);

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 44);
}

TEST(eraseTest, eraseMid) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.push_back(55);
  list.push_back(66);
  list.erase(1);

  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.front(), 44);
  EXPECT_EQ(list.back(), 66);
}
// reverse
TEST(reverseTest, reverseOne) {
  riki::LinkedList<int> list{};

  list.push_back(44);

  list.reverse();

  EXPECT_EQ(list.front(), 44);
}

TEST(reverseTest, reverseTwo) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.push_back(55);

  list.reverse();

  EXPECT_EQ(list.front(), 55);
  EXPECT_EQ(list.back(), 44);
}

TEST(reverseTest, reverseThree) {
  riki::LinkedList<int> list{};

  list.push_back(44);
  list.push_back(55);
  list.push_back(66);

  list.reverse();

  EXPECT_EQ(list.value_at(0), 66);
  EXPECT_EQ(list.value_at(1), 55);
  EXPECT_EQ(list.value_at(2), 44);
}
// Remove value
TEST(remove_valueTest, RemoveNone) {
  riki::LinkedList<int> list{};

  list.remove_value(5);

  EXPECT_EQ(list.size(), 0);
}

TEST(remove_valueTest, RemoveOnly) {
  riki::LinkedList<int> list{};

  list.push_back(5);
  list.remove_value(5);

  EXPECT_EQ(list.size(), 0);
}

TEST(remove_valueTest, RemoveFirst) {
  riki::LinkedList<int> list{};

  list.push_back(5);
  list.push_back(22);
  list.remove_value(5);

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front(), 22);
}

TEST(remove_valueTest, RemoveLast) {
  riki::LinkedList<int> list{};

  list.push_back(10);
  list.push_back(20);
  list.remove_value(20);

  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.back(), 10);
}

TEST(remove_valueTest, RemoveMid) {
  riki::LinkedList<int> list{};

  list.push_back(10);
  list.push_back(25);
  list.push_back(45);

  list.remove_value(25);

  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.front(), 10);
  EXPECT_EQ(list.back(), 45);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
