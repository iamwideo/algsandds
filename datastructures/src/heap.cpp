#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

#include <heap.h>

namespace data_structures {

Heap::Heap(const std::vector<int>& array) {
	heapArray = array;
	currentHeapSize = array.size();
	initialHeapSize = array.size();
}

int Heap::left(int elem) const {
	if(elem <= 0) {		
		throw std::out_of_range("Index starts at 1"); 
	}
	int left = elem * 2;
	if(left > currentHeapSize) {
		throw std::out_of_range("Can't go left"); 
	}
	return left;
}

int Heap::right(int elem) const {
	if(elem <= 0) {		
		throw std::out_of_range("Index starts at 1"); 
	}
	int right = elem * 2 + 1;
	if(right > currentHeapSize) {
		throw std::out_of_range("Can't go right"); 
	}
	return right;
}

int& Heap::at(int elem) {
	int access = elem-1;
	if(access >= 0 && access < currentHeapSize) {
		return heapArray.at(access);
	} else {		
		throw std::out_of_range("Can't access element " + std::to_string(access));
	}
}

const int& Heap::at(int elem) const {
	int access = elem-1;
	if(access >= 0 && access < currentHeapSize) {
		return heapArray.at(access);
	} else {		
		throw std::out_of_range("Can't access element " + std::to_string(access));
	}
}

int Heap::parent(int elem) const {
	if(elem <= 0) {		
		throw std::out_of_range("Index starts at 1"); 
	}
	if(elem < 2) {
		throw std::out_of_range("Can't go in parent"); 
	}
	return floor(elem / 2);
}

void Heap::buildMaxHeap() {
	for(int i = floor(currentHeapSize/2); i != 0; --i) {
		maxHeapify(i);
	}
}

std::vector<int> Heap::heap() const {
	return heapArray;
}

void Heap::maxHeapify(int elem) {
	int max = elem;
	try {
		max = (at(left(elem)) > at(elem)) ? left(elem) : elem;
	} catch(const std::out_of_range& exp) {
		std::cout << "No left child" << std::endl;
	}
	try {
		max = (at(right(elem)) > at(max)) ? right(elem) : max;
	} catch(const std::out_of_range& exp) {
		std::cout << "No right child" << std::endl;
	}

	if(elem != max) {
		int tmp = at(elem);
		at(elem) = at(max);
		at(max) = tmp;
		maxHeapify(max);
	}
}

}