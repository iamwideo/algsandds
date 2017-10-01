#ifndef INSERTION_SORT
#define INSERTION_SORT

#include <vector>

// insertion sort
// takes each element from 2 to n and compare it with the previous ones
// o(n^2) time O(1) spatial [in place]
void insertion_sort(std::vector<int>& a) {
    if(a.empty()) {
        return;
    }
    for(int i=1; i!=a.size(); ++i) {
        int key = a.at(i);
        int j = i - 1;
        while(j >= 0 && a.at(j) > key) {
            a.at(j+1) = a.at(j);
            --j;
        }
        a.at(j + 1) = key;
    }
}
#endif
