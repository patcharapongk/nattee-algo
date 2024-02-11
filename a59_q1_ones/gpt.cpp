#include <climits> // For INT_MAX
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Base case checking
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
  default:
    return INT_MAX; // Ensure a default return
  }
}

// q-array for calculations
const int q_arr_size = 10;
int q_arr[q_arr_size] = {0};

// Helper function to repeat a string
string repeat_str(string str, int times) {
  stringstream ss;
  for (int i = 0; i < times; ++i)
    ss << str;
  return ss.str();
}
void fill_q_arr() {
  for (int i = 0; i < q_arr_size; ++i) {
    string ans = repeat_str("1", i + 1);
    q_arr[i] = stoi(ans);
  }
}
// Find the index of the largest q_k that does not exceed target
int find_qk_index(int target) {
  int i = 0;
  while (i < q_arr_size && target >= q_arr[i])
    ++i;
  return i - 1; // Return the correct index of q_k
}

int original_target;
int find_count(int target, int count) {
  printf("t,c | %d %d\n", target, count);
  int abs_target = abs(target);
  if (abs_target < 12)
    return count + basecases(abs_target);

  int qk_idx = find_qk_index(target);

  // Ensure not to use q_k that leads back to the original target or beyond
  // array bounds
  if (qk_idx < 0)
    return INT_MAX; // Check for underflow

  int target_A = target - q_arr[qk_idx];
  int target_B = INT_MAX;
  if (qk_idx - 1 >= 0)
    target_B = target - q_arr[qk_idx - 1];

  // Recurse and find the minimal count of ones
  int countA =
      (target_A == original_target) ? INT_MAX : find_count(target_A, count + 1);
  int countB =
      (target_B == original_target) ? INT_MAX : find_count(target_B, count + 1);

  return min(countA, countB);
}

int main(int argc, char **argv) {
  original_target = (argc == 2) ? atoi(argv[1]) : 75;
  fill_q_arr();
  cout << "Minimal number of 1s: " << find_count(original_target, 0) << endl;
  return 0;
}

// Utility function to find minimum of two numbers
int min(int A, int B) { return (A < B) ? A : B; }
