#include <iostream>
#include <vector>

using namespace std;

/* Prep Lawn */
vector<int> A; // A : Lawn, A[i] : Plant Count,

/* Inputs */
int get_inputs(); // fill n,m,k
int fill_array(); // fill array with Plant Count data

int n; // n: lawn size
int m; // m: questions count
int k; // k: Price Multiplier ( 0 <= k <= 1000)

int a; // a: Starting point   ( always in range of n)
int b; // b: Money Allowance

/* Process Function */
/* We want to find the maximum tiles we can pay */

vector<int> cumulative_plants; // has cp[0] == 0 for simplicity.

int play(int money_usage, int current_tile) {
  printf("money_usage, current_tile : %d %d\n", money_usage, current_tile);
  if (money_usage > b || current_tile > n)
    return current_tile;

  // for each tile, multiply by k
  return play(money_usage + A[current_tile] * k, current_tile + 1);
}

int calc_money(int right_bound) {
  int money = 0;
  for (int i = a; i < right_bound; ++i)
    money += A[i];
  money += (right_bound - a) * k;
  return money;
}

void query_questions() {
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    int right_bound = play(0, a);
    cout << calc_money(right_bound) << endl;
  }
}

/* Helper fn */
template <typename T> void print_vector(const std::vector<T> &v) {
  for (const auto &x : v)
    std::cout << x << " ";
  std::cout << std::endl;
}

/* -------- MAIN ------- */
int main() {
  get_inputs();
  fill_array();
  query_questions();
  return 0;
}

int get_inputs() {
  cin >> n >> m >> k;
  if (k == 0)
    k = 1;
  A.resize(n);
  cumulative_plants.resize(n + 1);
  cumulative_plants[0] = 0;
  cout << endl << "---------" << endl;
  ;
  return 1;
}
int fill_array() {
  int plants_count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> plants_count;
    A[i] = plants_count;

    cumulative_plants[i + 1] = cumulative_plants[i] + plants_count;
  };
  return 1;
}
