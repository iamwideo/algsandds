#include "merge_sort.h"
#include "timer.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

TEST(MergeSort, SmallInput) {
    vector<int> input = {4,3,2,1}, expectedOutput = {1,2,3,4};
    vector<int> result;
    {
        Timer("InsertionSort", input.size());
        result = merge_sort(input);
    }
    EXPECT_EQ(result.size(), expectedOutput.size());
    for(int i = 0; i != expectedOutput.size(); ++i) {
        EXPECT_EQ(result.at(i), expectedOutput.at(i));
    }
}

TEST(MergeSort, EmptyVector) {
    vector<int> emptyVector;
    merge_sort(emptyVector);
}

TEST(MergeSort, VectorSize1) {
    vector<int> input = {1};
    merge_sort(input);
    EXPECT_EQ(1, input.at(0));
}

TEST(MergeSort, LargeInput) {
    int size = 10000;
    vector<int> input(size), expectedOutput(size);
    vector<int> result;
    for(int i = 0; i != size; ++i) {
        input.at(i) = size - i;
        expectedOutput.at(i) = i + 1;
    }
    {
        Timer t("MergeSort", input.size());
        result = merge_sort(input);
    }
    EXPECT_EQ(result.size(), expectedOutput.size());
    for(int i = 0; i != expectedOutput.size(); ++i) {
        EXPECT_EQ(result.at(i), expectedOutput.at(i));
    }
}
