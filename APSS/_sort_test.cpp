//
// Created by HansBlackCat on 8/6/20.
//

#include <vector>
#include <algorithm>
using namespace std;

void selection_sort(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        int INDEX = i;
        for (int j = i+1; j < A.size(); j++) {
            if (A[INDEX] > A[j]) {
                INDEX = j;
            }
        }
        swap(A[i], A[INDEX]);
    }
}

void insertion_sort(vector<int>& A) {
    for (int i = 0; i < A.size(); i++) {
        int j = i;
        while (j > 0 && A[j-1] > A[j]) {
            swap(A[j-1], A[j]);
            --j;
        }
    }
}

// O(N^2)
const int MIN = numeric_limits<int>::min();
int better_max_sum(const vector<int>& A) {
    int N = A.size();
    int ret = MIN;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];
            ret = min(sum, ret);
        }
    }
    return ret;
}

// O(NlogN)
int fast_max_sum(const vector<int>& A, int lo, int hi) {
    if (lo == hi) return A[lo];

    int mid = (lo + hi) >> 1;

    int left = MIN, right = MIN, sum = 0;
    for (int i = mid; i >= lo; --i) {
        sum += A[i];
        left = max(left, sum);
    }

    sum = 0;
    for (int j = mid+1; j <= hi; ++j) {
        sum += A[j];
        right = max(right, sum);
    }

    int single = max(fast_max_sum(A, lo, mid), fast_max_sum(A, mid+1, hi));

    return max(left + right, single);
}

// O(N)
int fastest_max_sum(const vector<int>& A) {
    int N = A.size(), ret = MIN, psum = 0;

    for (int i = 0; i < N; i++) {
        psum = max(psum, 0) + A[i];
        ret = max(psum, ret);
    }

    return ret;
}

int binsearch(const vector<int>& A, int x) {
    int n = A.size();
    int lo = -1, hi = n;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (A[mid] < x) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return hi;
}

void insertion_sort2(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
        int j = i;
        while (j > 0 && A[j-1] > A[j]) {
            swap(A[j-1], A[j]);
            --j;
        }
    }
}