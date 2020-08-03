//
// Created by HansBlackCat on 8/3/20.
//
#include <vector>
#include <string>

int paliLength(int i, int j, std::string str) {
    int len = 0;
    while (i >= 0 && j < str.size()) {
        if (str[i] == str[j]) {
            len = j - i + 1;
            j--;
            i++;
        } else {
            break;
        }
    }
    return len;
}

std::string longestPalindrome(std::string s) {
    int start = 0, end = 0;

    if(s.size() == 0) {
        return "";
    } else {
        for (int i = 0; i < s.size(); i++) {
            int len1 = paliLength(i, i, s);
            int len2 = paliLength(i, i+1, s);
            if (len1 > end - start) {
                start = i - len1/2;
                end = i + len1/2;
            }
            if (len2 > end - start) {
                start = i+1 - len2/2;
                end = i + len2/2;
            }
        }
    }
    return s.substr(start, end-start+1);


}

