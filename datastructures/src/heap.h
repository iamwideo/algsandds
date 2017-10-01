#ifndef INCLUDE_HEAP
#define INCLUDE_HEAP

#include <vector>

namespace data_structures {
	
class Heap {
private:
	std::vector<int> heapArray;
	// heapArray can be split in non valid parts
	int currentHeapSize;
	int initialHeapSize;

public:
	Heap(const std::vector<int>& array);

	int left(int elem) const;
	int right(int elem) const;

	const int& at(int elem) const;
	int& at(int elem);

	int parent(int elem) const;
	void maxHeapify(int elem);

	void buildMaxHeap();
	std::vector<int> heap() const;
};


}

#endif