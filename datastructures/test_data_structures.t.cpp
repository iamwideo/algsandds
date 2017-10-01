#include "heap.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <stdexcept>

using namespace std;
using namespace testing;
using namespace data_structures;

TEST(Heap, EmptyArrayAllFunctionThrows) {
   Heap heap({});

   EXPECT_THROW(heap.left(0), std::out_of_range);
   EXPECT_THROW(heap.right(0), std::out_of_range);
   EXPECT_THROW(heap.parent(0), std::out_of_range);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
