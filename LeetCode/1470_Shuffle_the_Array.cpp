//
// Created by HansBlackCat on 8/9/20.
//

#include <vector>
#include <string>
#include <istream>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
//    Input: nums = [2,5,1,3,4,7], n = 3
//    Output: [2,3,5,4,1,7]
//    Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

    vector<int> ret;

    for (int i = 0; i < n; i++) {
        ret.push_back(nums[i]);
        ret.push_back(nums[n + i]);
    }

    return ret;
}