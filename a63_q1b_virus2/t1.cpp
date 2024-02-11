#include <iostream>
#include <cmath>

using namespace std;
int n, k;
int arrSize;
vector<int> v;

// exclusive of last 
int count_ones(const vector<int> &v, int start, int end) {
    int count = 0;
    for (int i = start; i < end; i++) if (v[i] == 1) count++;
    return count;
}

// 1 == valid, 0 == invalid
int check_virus(int left, int right){
    if (right - left == 1) return 1;
    int mid = (right + left) >> 1;
    int left_count = count_ones(v, left, mid);
    int right_count = count_ones(v, mid, right);
    int diff = abs(left_count - right_count);
    // printf("l,r,d %d %d %d\n", left_count, right_count, diff);
    return (diff <= 1) && check_virus(left, mid) && check_virus(mid, right);
}

int main() {
    cin >> n >> k;
    arrSize = pow(2, k);
    v.resize(arrSize);
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < arrSize; k++) std::cin >> v[k];
        cout << (check_virus(0, arrSize) ? "yes" : "no") << endl;
    }
    return 0;
}
