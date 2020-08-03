//
// Created by HansBlackCat on 8/3/20.
//

#include "0001_Two_Sum.h"
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashmap {std::make_pair(nums[0], 0)};

    for (size_t i = 1; i < nums.size(); ++i) {
        auto it = hashmap.find(target - nums[i]);
        if (it != hashmap.end() && it -> second != i) {
            return { it -> second, int(i) };
        }
        hashmap[nums[i]] = i;
    }

    return {};
}