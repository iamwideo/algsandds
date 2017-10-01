#include <vector>
#include <cmath>
#include <iostream>

// merging the two vector in ascendent order
std::vector<int> merge(const std::vector<int>& left,
                            const std::vector<int>& right) {
    if(left.empty() && right.empty()) {
        return std::vector<int>();
    } else if(left.empty()) {
        return right;
    } else if(right.empty()) {
        return left;
    }
    int size = left.size() + right.size();
    std::vector<int> mergedVector;
    int leftIndex = 0, rightIndex = 0;
    for(int i = 0; i != size; ++i) {
        // explored completely left
        if(leftIndex >= left.size()) {
            mergedVector.push_back(right.at(rightIndex));
            ++rightIndex;
            continue;
        }
        // explored completely right
        if(rightIndex >= right.size()) {
            mergedVector.push_back(left.at(leftIndex));
            ++leftIndex;
            continue;
        }
        if(left.at(leftIndex) <= right.at(rightIndex)) {
            mergedVector.push_back(left.at(leftIndex));
            ++leftIndex;
        } else {
            mergedVector.push_back(right.at(rightIndex));
            ++rightIndex;
        }
    }
    return mergedVector;
}

std::vector<int> merge_sort(const std::vector<int>& input, int min, int max) {
    if(min < max-1) {
        int mid = floor((min + max)/2);
        auto left = merge_sort(input, min, mid);
        auto right = merge_sort(input, mid, max);
        const auto& result =  merge(left, right);
        return result;
    } else {
        return std::vector<int>{input.at(min)};
    }
}

std::vector<int> merge_sort(const std::vector<int>& input) {
    if(input.empty()) {
        return std::vector<int>();
    }
    return merge_sort(input, 0, input.size());
}
