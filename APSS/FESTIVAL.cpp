//
// Created by HansBlackCat on 8/5/20.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int C;
    cin >> C;

    while (C--) {
        int N,L;
        cin >> N >> L;

        vector<int> cost(N);
        for (int i = 0; i < N; i++) cin >> cost[i];

        double avg = 1e20;
        for (int i = 0, j; i < N - L + 1; i++) {
            int sum = 0;
            int count = 1;

            for (j = i; j < i + L - 1; j++, count++) {
                sum += cost[j];
            }

            for (; j < N; j++, count++) {
                sum += cost[j];
                avg = min(avg, (double)sum / count);
            }
        }
        printf("%.10lf\n", avg);
    }
}