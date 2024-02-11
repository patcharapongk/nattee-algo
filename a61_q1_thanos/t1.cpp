#include <cmath>
#include <iostream>
#include <tuple>

using namespace std;
vector<int> military_base;

/* Inputs */
int p;                  // Exponent for military_base size
int military_base_size; // Actual military_base size

int k; // Avengers count

/* Thanos Choices */
int A; // No avengers, -A power
int B; // With avengers, -B*k*l power

void get_inputs() {
  cin >> p >> k >> A >> B;
  military_base_size = (int)pow(2, p);
  military_base.resize(military_base_size);
}

void fill_avengers() {
  int index;
  for (int i = 0; i < k; ++i) {
    cin >> index;
    military_base[index - 1]++;
  };
}

int dc(int left, int right) {
  if (left == right) {
    if (military_base[left] > 0)
      return B * military_base[left];
    else
      return A;
  }

  return dc()
}

int main() {
  get_inputs();
  fill_avengers();
}
