#include <iostream>
#include <string>

using namespace std;
string a, b;
int k = 17;

bool similar_str(int left_a, int right_a, int left_b, int right_b,
                 int str_size) {
  if (str_size == 1)
    return a[left_a] == b[left_b];
  int half_size = str_size / 2;
  int mid_a = left_a + half_size;
  int mid_b = left_b + half_size;
  bool condition1 = similar_str(left_a, mid_a, left_b, mid_b, half_size) &&
                    similar_str(mid_a, right_a, mid_b, right_b, half_size);
  bool condition2 = similar_str(left_a, mid_a, mid_b, right_b, half_size) &&
                    similar_str(mid_a, right_a, left_b, mid_b, half_size);
  return condition1 || condition2;
}

int main() {
  cin >> a;
  cin >> b;

  // calculate length
  int length = a.length();

  bool result = similar_str(0, length, 0, length, length);
  (result) ? cout << "YES" : cout << "NO";
  cout << endl;

  return 0;
}
