//
// Created by HansBlackCat on 8/3/20.
//
#include <vector>


///////////////////////////////////////////////////////////////////////
double mediann(std::vector<int>& nums1, std::vector<int>& nums2) {
    size_t size1 = nums1.size();
    size_t size2 = nums2.size();

    if (size1 < size2) {
        return mediann(nums2, nums1);
    }

    return 3.0;

}