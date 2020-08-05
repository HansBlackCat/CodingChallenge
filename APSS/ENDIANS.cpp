//
// Created by HansBlackCat on 8/5/20.
//

#include <iostream>

struct Byte {
    char c1;
    char c2;
    char c3;
    char c4;
};

unsigned int convert(unsigned int a) {
    unsigned int result = 0;

    Byte *ipt = (Byte*) &a;
    Byte *opt = (Byte*) &result;

    opt -> c1 = ipt -> c4;
    opt -> c2 = ipt -> c3;
    opt -> c3 = ipt -> c2;
    opt -> c4 = ipt -> c1;

    return result;
}

int main() {
    int C;
    std::cin >> C;

    while (C--) {
        unsigned int N;
        std::cin >> N;
        std::cout << convert(N) << "\n";
    }
    std::cout << "\0";
}

