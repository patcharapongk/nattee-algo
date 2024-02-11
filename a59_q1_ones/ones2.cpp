#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// basecase checking
int basecases(int target) {
  switch (target) {
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

// q-array for calculations
// helper fn
string repeat_str(string str, int times);
int min(int A, int B);

const int q_arr_size = 10;
int q_arr[q_arr_size] = {0};
void fill_q_arr() {
  for (int i = 0; i < q_arr_size; ++i) {
    string ans = repeat_str("1", i + 1);
    q_arr[i] = stoi(ans);
  }
  cout << endl;
}

// calculations function
int find_qk_index(int target) {
  int i = 0;
  while (target > q_arr[i])
    ++i;
  return i;
}

int original_target;
int find_count(int target, int count) {
  printf("t,c %d %d \n", target, count);
  int abs_target = abs(target);
  if (abs_target < 12)
    return count + basecases(abs_target);
  int qk_idx = find_qk_index(target);

  int target_A = abs(target - q_arr[qk_idx]);
  int target_B = abs(target - q_arr[qk_idx - 1]);
  // avoid going back to original target
  printf("tA tB %d %d \n", target_A, target_B);
  if (target_A >= original_target)
    return INT_MAX;
  if (target_B >= original_target)
    return INT_MAX;

  // find min of both paths
  return min(find_count(target_A, count + qk_idx + 1),
             find_count(target_B, count + qk_idx));
}

// -------- MAIN -------
int main(int argc, char **argv) {
  if (argc == 2) {
    original_target = atoi(argv[1]);
  } else {
    original_target = 75;
  }
  fill_q_arr();
  cout << find_count(original_target, 0) << endl;
  return 0;
}

// ----- HELPER FUNCTIONS ----
string repeat_str(string str, int times) {
  stringstream ss;
  for (int i = 0; i < times; ++i)
    ss << str;
  return ss.str();
}
int min(int A, int B) { return (A <= B) ? A : B; }
