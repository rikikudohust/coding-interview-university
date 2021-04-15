#pragma once

namespace riki {

template <class T>
class LinkedList {
public:
    explicit LinkedList(): head(nullptr), size_(0) {}
    ~LinkedList();
    int size();
    bool isEmpty();
    T value_at(int index);
    void push_front(const T& value);
    T pop_front();
    void push_back(const T& value);
    T pop_back();
    T front();
    T back();
    void insert(int index,const T& value);
    void erase(int index);
    //T value_n_from_end(int index);
    void reverse();
    void remove_value(const T& val);
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val) : value(val), next(nullptr){}
    };
    Node* head;
    int size_;
};

}
