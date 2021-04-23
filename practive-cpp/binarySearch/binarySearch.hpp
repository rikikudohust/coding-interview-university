#pragma once
#include <vector>
#include <iostream>


int binarySearch(std::vector<int> set, int target){
    int low = 0;
    int high = set.size() - 1;
    int mid;
    while (low <=  high) {
        mid = (low + high) /2;
        if (set[mid] < target) {
            low = mid + 1;
        } else if ( set[mid] > target ) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int binarySearchRecur(std::vector<int> set, int first, int last, int target) {
    if (first > last) {
        return -1;
    }
    int mid = (first + last)/2;
    if (set[mid] > target) {
        return binarySearchRecur(set, first, mid - 1, target);
    } else if (set[mid] < target){
        return binarySearchRecur(set,mid + 1, last, target);
    } else 
        return mid;
}
