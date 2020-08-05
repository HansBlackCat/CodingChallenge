//
// Created by HansBlackCat on 8/5/20.
//

#include <iostream>

int main() {
    int C;
    std::cin >> C;

    while (C--) {
        int tup[3][2];

        int tmp;
        static int mem = 0;

        for (int i = 0; i < 6; i++) {
            std::cin >> tmp;

            if (mem == 0) {
                tup[i][0] = tmp - '0';
                mem = 1;
            } else {
                tup[i][1] = tmp - '0';
                mem = 0;
            }

        }

        for (int i = 0; i < 2; i++) {
            if (tup[i][0] != tup[i+1][0]) {
                int rest;
                if (i == 0) {
                    rest = 2;
                } else {
                    rest = 0;
                }

                int o1 = tup[i][0] + tup[i+1][0] - tup[rest][0];
                int o2 = tup[i][1] + tup[i+1][1] - tup[rest][1];
                std::cout << o1 << " " << o2 << '\n';
                break;
            } else {
                int rest = 1;

                int o1 = tup[0][0] + tup[2][0] - tup[rest][0];
                int o2 = tup[0][1] + tup[2][1] - tup[rest][1];
                std::cout << o1 << " " << o2 << '\n';
                break;
            }
        }

    }
    std::cout << '\0';
}