#include "insertion_sort.h"
#include "utility.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

using namespace std;
using namespace testing;

TEST(InsertionSort, SmallInput) {
      vector<int> input = {4,3,2,1}, expectedOutput = {1,2,3,4};
      {
          Timer("InsertionSort", input.size());
          insertion_sort(input);
      }
      EXPECT_EQ(input.size(), expectedOutput.size());
      for(int i = 0; i != expectedOutput.size(); ++i) {
          EXPECT_EQ(input.at(i), expectedOutput.at(i));
      }
}

TEST(InsertionSort, EmptyVector) {
      vector<int> emptyVector;
      insertion_sort(emptyVector);
}

TEST(InsertionSort, VectorSize1) {
      vector<int> input = {1};
      insertion_sort(input);
      EXPECT_EQ(1, input.at(0));
}

TEST(InsertionSort, LargeInput) {
    int size = 10000;
    vector<int> input(size), expectedOutput(size);
    for(int i = 0; i != size; ++i) {
        input.at(i) = size - i;
        expectedOutput.at(i) = i + 1;
    }
          {
              Timer t("InsertionSort", input.size());
              insertion_sort(input);
          }
          EXPECT_EQ(input.size(), expectedOutput.size());
          for(int i = 0; i != expectedOutput.size(); ++i) {
              EXPECT_EQ(input.at(i), expectedOutput.at(i));
          }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
