//
// Created by HansBlackCat on 8/30/20.
//

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int SIZE = nums.size();
        int ANS = nums[0]+nums[1]+nums[2];

        sort(begin(nums), end(nums));
        for (int i = 0; i < SIZE; i++) {
            int i_lo = i+1;
            int i_hi = SIZE-1;
            while (i_lo < i_hi) {
                int sum = nums[i] + nums[i_lo] + nums[i_hi];
                if (abs(target - sum) < abs(target - ANS)) {
                    ANS = sum;
                }

                if (target < sum) {
                    i_hi--;
                } else {
                    i_lo++;
                }
            }
        }

        return ANS;
    }
};