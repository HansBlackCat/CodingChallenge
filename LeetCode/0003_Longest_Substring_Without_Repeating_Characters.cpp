//
// Created by HansBlackCat on 8/3/20.
//
#include <vector>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    std::vector<char> charVec;
    int ans = 0;

    // for (char & i : s) // range base for
    for (size_t i = 0; i < s.size(); ++i) {
            auto it = std::find(charVec.begin(), charVec.end(), s[i]);
            if (it != charVec.end()) {
                if (ans < charVec.size()) {
                    ans = charVec.size();
                }
                it++;
                charVec.erase(charVec.begin(), it);
            }
            charVec.push_back(s[i]);
    }

    if (ans < charVec.size()) {
        ans = charVec.size();
    }

    return ans;
}