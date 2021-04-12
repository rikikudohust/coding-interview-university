#pragma once

#include <iostream>
#include <memory>

namespace riki {
static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
static const int kShrinkFactor = 4;

template <class T>
class JVector {
public:
    JVector();
    JVector(int capacity);
    ~JVector();
    int size();
    int capacity();
    bool isEmpty();
    T& at(int index);
    void push(const T& item);
    void insert(const int& index,const T& item);
    void prepend(const T& item);
    void pop();
    void del(const int& index);
    void remove(const T& item);
    int find(const T& item);
    //void resize();
private:
    int cap{kMinCapacity};
    int size_{0};
    std::unique_ptr<T[]> data;
    int DetermineCapacity(int cap);
    void ResizeCapacity(int cap);
    void IncreaseSize();
    void DecreaseSize();
};
}
