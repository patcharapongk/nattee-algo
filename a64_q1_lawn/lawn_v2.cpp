#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

/* Prep Lawn */
vector<int> S; // S: Cumulative Lawn Plants

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

void query_questions() {
  cout << endl << " ------------- " << endl;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    int left = a + 1;
    auto upper_bound_it =
        upper_bound(S.begin() + left, S.end(), S[left - 1] + b);
    int plants_mowed = 0;
    for (auto it = S.begin() + left; it < upper_bound_it; it++) {
      plants_mowed += *it;
    }
    cout << plants_mowed << endl;
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
  S.resize(n + 1); // Cumulative, reserve for 0th index as 0.
  S[0] = 0;
  return 1;
}
int fill_array() {
  int plants_count = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> plants_count;
    S[i] = S[i - 1] + plants_count + k;
  };

  return 1;
}
