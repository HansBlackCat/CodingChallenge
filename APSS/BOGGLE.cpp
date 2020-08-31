//
// Created by HansBlackCat on 8/13/20.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1};
int board[5][5];

bool inRange(int y, int x) {
    return ((0 <= y) && (y < 5) && (0 <= x) && (x < 5));
}

bool hasWord(int y, int x, const string& word) {
    // Basis1 - if out of range
    if (!inRange(y, x)) return false;
    // Basis2 - if fst word is different
    if (word[0] != board[y][x]) return false;
    // Basis3 - if length == 1 always true
    if (word.size() == 1) return true;

    for (int dir = 0; dir < 8; ++dir) {
        int nextY = y + dy[dir], nextX = x + dx[dir];
        if (hasWord(nextY, nextX, word.substr(1))) {
            return true;
        }
    }
    return false;
}

string b_to_word(bool b) {
    return b ? "YES" : "NO";
}

int main() {
    int CASE;
    cin >> CASE;

    while (CASE--) {
        string vec1, vec2, vec3, vec4, vec5;
        cin >> vec1 >> vec2 >> vec3 >> vec4 >> vec5;
        for (int i = 0; i < 5; i++) {
            board[0][i] = vec1[i];
            board[1][i] = vec2[i];
            board[2][i] = vec3[i];
            board[3][i] = vec4[i];
            board[4][i] = vec5[i];
        }

        int WORD_NUM;
        cin >> WORD_NUM;
        while(WORD_NUM--) {
            string word = "";
            cin >> word;
            cout << word << " " << b_to_word(hasWord(2, 2, word)) << "\n";
        }

        cout << '\0';
    }
}
