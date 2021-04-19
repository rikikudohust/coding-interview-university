#pragma once 
#include "hashObject.hpp"
#include <iostream>
#include <memory>
#include <string>

class HashTable {
public:
    explicit HashTable(int size);
    ~HashTable();
    void add(HashObject* object);
    bool exist(const std::string& key);
    std::string get(const std::string& key);
    void remove(const std::string& key);
    void printDebug();
private:
    int size_;
    std::unique_ptr<HashObject[]> data;
    int Hash(const std::string& key);
};

