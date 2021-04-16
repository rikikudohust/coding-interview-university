#pragma once

namespace riki {
    
template <class T>
class Queue {
public:
    explicit Queue(): head_(nullptr), tail_(nullptr) {};
    ~Queue();
    void enqueue(const T& value);
    T dequeue();
    bool isEmpty();
private:
    struct NodeQ {
        T value;
        NodeQ* next;
        NodeQ(const T& val) : value(val) {}
    };
    NodeQ* head_;
    NodeQ* tail_;
};

}
