#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

/* Prep Lawn */
vector<int> A; // A : Lawn, A[i] : Plant Count,

/* Inputs */
int get_inputs(); // fill n,m,k
int fill_array(); // fill array with Plant Count data

ll n;  // n: lawn size
ll m;  // m: questions count
int k; // k: Price Multiplier ( 0 <= k <= 1000)

ll a; // a: Starting point   ( always in range of n)
ll b; // b: Money Allowance

/* Process Function */
/* We want to find the maximum tiles we can pay */

int play(int money_usage, int current_tile, int plants_mowed) {
  if (current_tile > n || money_usage > b)
    return plants_mowed - A[current_tile - 1];

  // for each tile, multiply by k
  return play(money_usage + A[current_tile] + k, current_tile + 1,
              plants_mowed + A[current_tile]);
}

void query_questions() {
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    ll right_bound = play(0, a, 0);
    cout << right_bound << "\n";
  }
}

/* -------- MAIN ------- */
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  get_inputs();
  fill_array();
  query_questions();
  return 0;
}

int get_inputs() {
  cin >> n >> m >> k;
  A.resize(n);
  return 1;
}
int fill_array() {
  int plants_count = 0;
  for (int i = 0; i < n; ++i) {
    cin >> plants_count;
    A[i] = plants_count;
  };
  return 1;
}
