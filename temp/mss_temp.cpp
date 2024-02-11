#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int get_sum(const std::vector<int> &S, int a, int b) { return S[b] - S[a - 1]; }

int mss(const std::vector<int> &A, int start, int stop,
        const std::vector<int> &S) {
  if (start == stop) {
    return A[start];
  }
  int m = (start + stop) / 2;
  int r1 = mss(A, start, m, S);
  int r2 = mss(A, m + 1, stop, S);

  int max_sum_left = get_sum(S, m, m);
  for (int i = start; i <= m - 1; ++i) {
    max_sum_left = std::max(max_sum_left, get_sum(S, i, m));
  }

  int max_sum_right = get_sum(S, m + 1, m + 1);
  for (int j = m + 2; j <= stop; ++j) {
    max_sum_right = std::max(max_sum_right, get_sum(S, m + 1, j));
  }
  int r3 = max_sum_left + max_sum_right;
  return std::max({r1, r2, r3});
}

int mss1(vector<int> &A) {
  vector<int> S(A.size() + 1);
  S[0] = 0;
  for (int i = 1; i <= A.size(); i++) {
    S[i] = S[i - 1] + A[i];
  }
  return mss(A, 1, A.size(), S);
}

int main() {
  int N, temp;

  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> temp;
    arr[i] = temp;
  }

  cout << mss1(arr);
}
