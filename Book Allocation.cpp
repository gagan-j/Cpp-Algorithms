#include <iostream>
#include <vector>
using namespace std;

bool isvalid(vector<int> ar, int mid, int n, int m) {
    int page = 0;
    int student = 1;
    for (int i = 0; i < n; i++) {
        if (ar[i] > mid) {
            return false;
        }
        if (page + ar[i] <= mid) {
            page += ar[i];
        } else {
            student++;
            page = ar[i];
        }
    }
    return (student > m) ? false : true;
}

int bookalo(vector<int> ar, int n, int m) {
    if (m > n) {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar[i];
    }
    int st = 0;
    int end = sum;
    int ans = 0;
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isvalid(ar, mid, n, m)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> ar{40,30,10,20};
    int n = 4, m = 2;
    cout << bookalo(ar, n, m) << endl;
    return 0;
}