//
// Created by HansBlackCat on 8/30/20.
//
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    string reorganizeString(string S) {
        int SIZE = S.size();
        vector<int> vec(26);

        int most_freq = 0, i = 0;

        for (auto c: S) {
            if (++vec[c - 'a'] > vec[most_freq]) {
                most_freq = c - 'a';
            }
        }

        if (2 * vec[most_freq] - 1 > SIZE) return "";

        while (vec[most_freq]--) {
            S[i] = ('a' + most_freq);
            i += 2;
        }
        vec[most_freq] = 0;

        for (int j = 0; j < 26; j++) {
            while (vec[j]--) {
                if (i >= SIZE) i = 1;
                S[i] = ('a' + j);
                i += 2;
            }
        }

        return S;
    }
};


