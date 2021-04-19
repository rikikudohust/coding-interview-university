#pragma once
#include <iostream>
#include <string>

class HashObject {
public:
    HashObject() {}
    ~HashObject(){}
    void setKey(const std::string& key) {
        this->key = key;
    }
    void setValue(const std::string& value) {
        this->value = value;
    }
    std::string getKey() {
        return key;
    }
    std::string getValue() {
        return value;
    }
    static const std::string getKeyNull() {
        return "<null>";
    }
    static const std::string getDummyKey() {
        return "<dummy>";
    }
    void setDummyKey() {
        key = getDummyKey();
        value = "";
    }
private:
    std::string key;
    std::string value;
};
