
#include <iostream>
#include "linkedlist.hpp"
namespace riki {

template <class T>
LinkedList<T>::~LinkedList<T>(){}
template <class T>
int LinkedList<T>::size() {
    return size_;
}
template <class T>
bool LinkedList<T>::isEmpty(){
    return head == nullptr;
}
template <class T>
T LinkedList<T>::value_at(int index) {
    if (index < 0 || index >= size_) {
        std::cerr << "Index out of bound\n";
        exit(EXIT_FAILURE);
    }
    Node* current = head; 
    while (index > 0) {
        current = current->next;
        --index;
    }
    return current->value;
}
template <class T>
void LinkedList<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    ++size_;
}
template <class T>
T LinkedList<T>::front() {
    if (head == nullptr) {
        std::cerr << "LinkedList is empty!\n";
        exit(EXIT_FAILURE);
    }
    return head->value;
}
template <class T>
void LinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        ++size_;
        return;
    }
    Node* current = head;
    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
    ++size_;
}
template <class T>
T LinkedList<T>::back() {
    if (head == nullptr) {
        std::cerr << "LinkedList is empty!\n";
        exit(EXIT_FAILURE);
    }
    Node* current = head;
    while(current->next) {
        current = current->next;
    }
    return current->value;
}
template <class T>
T LinkedList<T>::pop_back() {
    if (head == nullptr) {
        std::cerr << "LinkedList is empty!\n";
        exit(EXIT_FAILURE);
    }
    T temp;
    Node* prev = head;
    Node* current = head->next;;
    if (current) {
        while(current->next != nullptr) {
            current = current->next;
        }
        temp = current->value;
        delete current;
        prev->next =  nullptr;
    } else {
        temp = prev->value;
        delete prev;
    }
    --size_;
    return temp;
}
template <class T>
T LinkedList<T>::pop_front() {
   if (head == nullptr) {
        std::cerr << "LinkedList is empty!\n";
        exit(EXIT_FAILURE);
    }
   T temp = head->value;
   Node* prev = head;
   head = head->next;
   delete prev;
   --size_;
   return temp;
}
template <class T>
void LinkedList<T>::insert(int index, const T& value) {
    if (index < 0 || index > size_) {
        std::cerr << "Index out of bound\n";
        exit(EXIT_FAILURE);
    }
    if (index == 0) {
        push_front(value);
        return;
    } else if (index == size_) {
        push_back(value);
        return;
    }
    Node* current = head;
    Node* newNode = new Node(value);
    while (index > 1) {
        current = current->next;
        --index;
    }
    newNode->next = current->next;
    current->next = newNode;
    ++size_;
}
template <class T>
void LinkedList<T>::erase(int index) {
    if (index < 0 || index > size_) {
        std::cerr << "Index out of bound\n";
        exit(EXIT_FAILURE);
    }
    // If index = 0 then Delete head
    if (index == 0) {
        pop_front();
        return;
    }
    Node* current = head;
    Node* prev = head;
    while (index > 1) {
        prev = prev->next;
        --index;
    }
    while (index > 0) {
        current = current->next;
        --index;
    }
    prev->next = current->next;
    delete current;
    --size_;
}
//template <class T>
//T LinkedList<T>::value_n_from_end(int index) {
//}
template <class T>
void LinkedList<T>::reverse() {
    Node* temp1 = nullptr;
    if (head->next == nullptr) {
        return;
    }
    Node* temp2 = head->next;
    while (temp2  != nullptr) {
        head->next = temp1;
        temp1 = head;
        head = temp2;
        temp2 = head->next;
    }
    head->next = temp1;
}
template<class T>
void LinkedList<T>::remove_value(const T& val) {
    Node* temp = nullptr;
    Node* cur = head;
    while(cur) {
        if (cur->value == val) {
            if (temp == nullptr) {
                head = cur->next;
            } else {
                temp->next = cur->next;
            }
            delete cur;
            --size_;
            break;
        }
        temp = cur;
        cur = cur->next;
    }
}
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<std::string>;
template class LinkedList<bool>;
}

