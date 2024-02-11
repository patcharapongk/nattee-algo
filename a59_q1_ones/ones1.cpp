#include <climits>
#include <iostream>

using namespace std;

// fill basecases
int basecases(int n) {
  switch (n) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 4;
  case 5:
    return 5;
  case 6:
    return 6;
  case 7:
    return 6;
  case 8:
    return 5;
  case 9:
    return 4;
  case 10:
    return 3;
  case 11:
    return 2;
  }
}
const int q_arr_size = 11;
int q_arr[q_arr_size] = {0};

// input helper
int n;
int get_input() {
  cin >> n;
  if (n < 1 || n > 1e9) {
    std::cerr << "n out of range\n";
    return 0;
  }
  return 1;
}

// find counts
int min_counts = INT_MAX;
void find_count(int target) {
  int count = 0;
  if (count < min_counts) {
    min_counts = count;
    cout << "New count found: " << count << endl;
  }
}

// main function
int main() {
  if (!get_input())
    return 1;

  return 0;
}
