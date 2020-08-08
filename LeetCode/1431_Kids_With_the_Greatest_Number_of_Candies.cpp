//
// Created by HansBlackCat on 8/9/20.
//

// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

//    Input: candies = [2,3,5,1,3], extraCandies = 3
//    Output: [true,true,true,false,true]
//    Explanation:
//    Kid 1 has 2 candies and if he or she receives all extra candies (3) will have 5 candies --- the greatest number of candies among the kids.
//            Kid 2 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.
//            Kid 3 has 5 candies and this is already the greatest number of candies among the kids.
//            Kid 4 has 1 candy and even if he or she receives all extra candies will only have 4 candies.
//            Kid 5 has 3 candies and if he or she receives at least 2 extra candies will have the greatest number of candies among the kids.

    int VALUE = 0;
    for (int i = 0; i < candies.size(); i++) {
        if (VALUE < candies[i]) {
            VALUE = candies[i];
        }
    }

    vector<bool> ret;
    for (int j = 0; j < candies.size(); j++) {
        ret.push_back(extraCandies + candies[j] >= VALUE);
    }

    return ret;
}