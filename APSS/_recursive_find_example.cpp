//
// Created by HansBlackCat on 8/13/20.
//

#include <vector>
#include <iostream>
using namespace std;

void printPicked(vector<int> picked) {
    int N = picked.size();

    cout << '<';
    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << picked[i];
            break;
        }
        cout << picked[i] << ", ";
    }
    cout << '>' << endl;
}

void pick(int N, vector<int> picked, int toPick) {
    if (toPick == 0) {
        printPicked(picked);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int next = smallest; next < N; ++next) {
        picked.push_back(next);
        pick(N, picked, toPick-1);
        picked.pop_back();
    }
}

//int main() {
//    vector<int> emt;
//    pick(10, emt, 5);
//}

