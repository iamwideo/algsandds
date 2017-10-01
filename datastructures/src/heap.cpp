#include <vector>
#include <heap.h>
#include <stdexcept>

namespace data_structures {

Heap::Heap(const std::vector<int>& array) {
	heapArray = array;
	currentHeapSize = initialHeapSize = array.size();
}

int Heap::left(int elem) const {
	int left = elem * 2;
	if(left > currentHeapSize) {
		throw std::out_of_range("Can't go left"); 
	}
	return heapArray.at(left);
}

int Heap::right(int elem) const {
	int right = elem * 2 + 1;
	if(right > currentHeapSize) {
		throw std::out_of_range("Can't go right"); 
	}
	return heapArray.at(right);
}

int Heap::parent(int elem) const {
	if(elem < 2) {
		throw std::out_of_range("Can't go in parent"); 
	}
	int parent = elem / 2;
	return heapArray.at(parent);
}

}