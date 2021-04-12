#include "jvector.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace riki {

template<class T>
JVector<T>::JVector() {
    cap = kMinCapacity;
    data = std::make_unique<T[]>(cap);
}

template <class T>
JVector<T>::JVector(int cap) {
    if (cap < 1) {
        std::cout << "Cannot make vector with this size\n";
        exit(EXIT_FAILURE);
    }
    int true_capacity = DetermineCapacity(cap);
    this->cap= true_capacity;
    data = std::make_unique<T[]>(true_capacity);
}

template<class T>
JVector<T>::~JVector() {}

template<class T>
int JVector<T>::DetermineCapacity(int cap) {
    int true_capacity = kMinCapacity;
    while (cap > true_capacity / kGrowthFactor) {
        true_capacity *= kGrowthFactor;
    }
    return true_capacity;
}

template <class T>
void JVector<T>::ResizeCapacity(int candidate_cap) {
    if (cap < candidate_cap) {
        if (size_ == cap) {
            IncreaseSize();
        }
    } else if (cap > candidate_cap) {
        if (size_ < cap / kGrowthFactor) {
            DecreaseSize();
        }
    }
}

template <class T>
void JVector<T>::IncreaseSize() {
    int old_capacity = cap;
    int new_capacity = DetermineCapacity(old_capacity);
    if (old_capacity != new_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
        for (int i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        data = std::move(new_data);
        cap = new_capacity;
    }

}

template <class T>
void JVector<T>::DecreaseSize() {
    int old_capacity = cap;
    int new_capacity = old_capacity/2;
    if (new_capacity < kMinCapacity) {
        new_capacity = kMinCapacity;
    } else if (new_capacity != old_capacity) {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
        for (int i =  0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        data = std::move(new_data);
        cap = new_capacity;
    }
}

template <class T>
int JVector<T>::size() {
    return size_;
}

template<class T>
int JVector<T>::capacity() {
    return cap;
}
template<class T>
bool JVector<T>::isEmpty() {
    if (size_ == 0) {
        return true;
    } 
    return false;
}

template<class T>
T& JVector<T>::at(int index) {
    if (index < 0 || index >= size_) {
        std::cout << "Can't get value of this index\n";
        exit(EXIT_FAILURE);
    }
    return data[index];
}

template<class T>
void JVector<T>::push(const T& item) {
    ResizeCapacity(size_+1);
    data[size_] = item; 
    ++size_;
}

template<class T>
void JVector<T>::insert(const int& index, const T& item) {
    if (index < 0 || index >= size_) {
        std::cout << "Can't get value of this index\n";
        exit(EXIT_FAILURE);
    }
    ResizeCapacity(size_+1);
    for (int i = size_; i > index; --i) {
        data[i] = data[i-1];
    }
    data[index] = item;
    ++size_;
}

template<class T> 
void JVector<T>::prepend(const T& item) {
    insert(0, item);
}
template<class T>
void JVector<T>::pop() {
    if (size_ == 0) {
        std::cout << "container is empty\n";
        exit(EXIT_FAILURE);
    }
    ResizeCapacity(size_ - 1);
    --size_;
}

template<class T>
void JVector<T>::del(const int& index) {
    if (index < 0 || index >= size_) {
        std::cout << " Can't remove valua in this index\n";
        exit(EXIT_FAILURE);
    }
    ResizeCapacity(size_-1);
    for (int i = index; i < size_ - 1; ++i) {
        data[i] = data[i+1];
    }
    --size_;
}
template<class T>
void JVector<T>::remove(const T& item) {
    for (int i = size_- 1; i >= 0; --i ) {
        if (data[i] == item) {
            del(i);
        }
    }
}
template<class T>
int JVector<T>::find(const T& item) {
    int result = -1;
    for (int i = 0; i < size_; ++i) {
        if (data[i] == item) {
            result = i;
            break;
        }
    }
    return result;
}
template class JVector<int>;
template class JVector<std::string>;
template class JVector<double>;
template class JVector<char>;
}
