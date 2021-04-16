#include <iostream>
#include "queue.hpp"
#include <string>

namespace riki {

template <class T>
Queue<T>::~Queue(){}

template <class T>
    void Queue<T>::enqueue(const T& value) {
        NodeQ* cur = new NodeQ(value);
        if (head_ == nullptr) {
            tail_ = cur;
            head_ = cur;
        } else {
            tail_->next = cur;
            tail_ = tail_->next;
        }
    }
template<class T>
    T Queue<T>::dequeue() {
        if (head_ == nullptr) {
            std::cout << "Queue is Empty";
            exit(EXIT_FAILURE);
        }
        T temp = head_->value;
        if (head_ == tail_) {
            delete tail_;
        } else {
            NodeQ* cur = head_->next;
            delete head_;
            head_ = cur;
        }
        return temp;
    }    

template<class T>
    bool Queue<T>::isEmpty() {
        return head_ == nullptr;
    }
template class Queue<int>;
template class Queue<double>;
template class Queue<std::string>;
template class Queue<char>;
template class Queue<bool>;
}
