#include "heap.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;
using namespace testing;
using namespace data_structures;

TEST(Heap, ZeroIsNotValid) {
    Heap heap({1});

    EXPECT_THROW(heap.left(0), std::out_of_range);
    EXPECT_THROW(heap.right(0), std::out_of_range);
    EXPECT_THROW(heap.parent(0), std::out_of_range);
    EXPECT_THROW(heap.at(0), std::out_of_range);
}

TEST(Heap, EmptyArrayAllFunctionThrows) {
    Heap heap({});

    EXPECT_THROW(heap.left(1), std::out_of_range);
    EXPECT_THROW(heap.right(1), std::out_of_range);
    EXPECT_THROW(heap.parent(1), std::out_of_range);
}

TEST(Heap, OneElementStillThrows) {
    Heap heap({1});

    EXPECT_THROW(heap.left(1), std::out_of_range);
    EXPECT_THROW(heap.right(1), std::out_of_range);
    EXPECT_THROW(heap.parent(1), std::out_of_range);
}

TEST(Heap, LeftChild) {
    Heap heap({1, 2, 3});

    EXPECT_EQ(2, heap.at(heap.left(1)));
}

TEST(Heap, RightChild) {
    Heap heap({1, 2, 3});

    EXPECT_EQ(3, heap.at(heap.right(1)));
}

TEST(Heap, ParentFromLeft) {
    Heap heap({1, 2, 3});

    EXPECT_EQ(1, heap.at(heap.parent(heap.left(1))));
}

TEST(Heap, ParentFromRight) {
    Heap heap({1, 2, 3});

    EXPECT_EQ(1, heap.at(heap.parent(heap.right(1))));
}

TEST(Heap, MaxHeapify) {
    Heap heap({1, 2, 3});
    vector<int> expectedResult = {3, 2, 1};

    vector<int> result;
    EXPECT_NO_THROW(heap.buildMaxHeap());
	result = heap.heap();
    for(int i = 0; i != expectedResult.size(); ++i) {
    	EXPECT_EQ(expectedResult.at(i), result.at(i));
    }

}

TEST(Heap, MaxHeapifyHarder) {
    Heap heap({4,1,3,2,16,9,10,14,8,7});
    vector<int> expectedResult = {16,14,10,8,7,9,3,2,4,1};

    vector<int> result;
    EXPECT_NO_THROW(heap.buildMaxHeap());
	result = heap.heap();
    for(int i = 0; i != expectedResult.size(); ++i) {
    	EXPECT_EQ(expectedResult.at(i), result.at(i));
    }

}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
