#include <gtest/gtest.h>
#include "hashtable.hpp"

TEST(ExistTest, Exist) {
    HashTable states(100);
    HashObject tx;
    tx.setKey("Texas");
    tx.setValue("Austin");
    states.add(&tx);
    HashObject ca;
    ca.setKey("California");
    ca.setValue("Sacramento");
    states.add(&ca);
    EXPECT_TRUE(states.exist("Texas"));
}
TEST(ProbingTest, Highload) {
    HashTable states(8);

    HashObject tx;
    tx.setKey("Texas");
    tx.setValue("Austin");

    HashObject ca;
    ca.setKey("California");
    ca.setValue("Sacramento");

    HashObject nm;
    nm.setKey("New Mexico");
    nm.setValue("Santa Fe");

    HashObject fl;
    fl.setKey("Florida");
    fl.setValue("Tallahassee");

    HashObject oregon;
    oregon.setKey("Oregon");
    oregon.setValue("Salem");

    HashObject wa;
    wa.setKey("Washington");
    wa.setValue("Olympia");


    HashObject ut;
    ut.setKey("Utah");
    ut.setValue("Salt Lake City");

    HashObject ny;
    ny.setKey("New York");
    ny.setValue("Albany");

    HashObject mn;
    mn.setKey("Minnesota");
    mn.setValue("St. Paul");

    states.add(&tx);
    states.add(&ca); 
    states.add(&nm);
    states.add(&fl);
    states.add(&oregon);
    states.add(&wa);
    states.add(&ut);
    states.add(&ny);
    states.add(&mn);
    EXPECT_TRUE(states.exist("Texas"));
    EXPECT_TRUE(states.exist("New Mexico"));
    EXPECT_TRUE(states.exist("Florida"));
    EXPECT_TRUE(!states.exist("Minnesota"));
}

TEST(GetTest, get1) {
    HashTable states(100);
    HashObject tx;
    tx.setKey("Texas");
    tx.setValue("Austin");
    states.add(&tx);
    EXPECT_EQ("Austin",states.get("Texas"));
}

TEST(RemoveTest, remove1) {
    HashTable states(100);
    HashObject tx;
    tx.setKey("Texas");
    tx.setValue("Austin");
    states.add(&tx);
    EXPECT_TRUE(states.exist("Texas"));
    states.remove("Texas");
    EXPECT_FALSE(states.exist("Texas"));
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
