#include "hashtable.hpp"
#include <cmath>

HashTable::HashTable(int size) {
    size_ = size;
    data = std::make_unique<HashObject[]>(size_);
    for (int i = 0; i < size_; ++i) {
        data[i].setKey(HashObject::getKeyNull());
    }
}

HashTable::~HashTable(){}

int HashTable::Hash(const std::string& key) {
    int hash = 0;
    int key_length = static_cast<int>(key.length());
    for (int i = 0; i < key_length; ++i) {
        hash = hash * 31 + (int)key[i];
    }
    return abs(hash % size_);
}

bool HashTable::exist(const std::string& key) {
    int index = Hash(key);
    int origin = index;
    bool found = false;
    while (data[index].getKey() != HashObject::getKeyNull()) {
        if (key == data[index].getKey()) {
            found = true;
            break;
        }
        index = (index + 1) % size_;
        if (index == origin) {
            break;
        }
    }
    return found;
}

void HashTable::add(HashObject* object) {

    int dummy = -1;
    bool found = false;
    int index = Hash(object->getKey());
    int origin = index;
    
    while (data[index].getKey() != HashObject::getKeyNull()) {
        if (data[index].getKey() == object->getKey()) {
            found = true;
            break;
        } else if (data[index].getKey() == HashObject::getDummyKey()) {
            dummy = index;
        }
        index = (index + 1) % size_;
        if (index == origin) {
            return;
        }
    }
    if (!found && dummy != -1) {
        index = dummy;
    }
    data[index].setKey(object->getKey());
    data[index].setValue(object->getValue());
}

std::string HashTable::get(const std::string& key) {
    int index = Hash(key);
    int origin = index;
    while (data[index].getKey() != HashObject::getKeyNull()) {
        if (data[index].getKey() == key) {
            return data[index].getValue();
        }
        index = (index + 1) % size_;
        if (index == origin) {
            break;
        }
    }
    return nullptr;
}

void HashTable::remove(const std::string& key) {
    int index = Hash(key);
    int origin = index;
    while (data[index].getKey() != HashObject::getKeyNull()) {
        if (data[index].getKey() == key) {
            data[index].setKey(HashObject::getDummyKey());
            data[index].setValue("");
            break;
        }
        index = (index + 1) % size_;
        if (index == origin) {
            break;
        }
    }
}

void HashTable::printDebug() {
    for (int i = 0; i < size_ ; ++i) {
        std::cout << i << ":" << data[i].getKey() << ":"<< data[i].getValue()
         << std::endl;
    }
    std::cout << "...............................\n";
}
