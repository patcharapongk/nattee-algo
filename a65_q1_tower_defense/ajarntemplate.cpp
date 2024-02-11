#include <algorithm>
#include <iostream>
#include <vector>
#include <map> 

using namespace std;

vector<int> t,p; 
map<int, int> h;

int w;
int n,m,k;
int combined_health;

void process() {
    // for each tower, check if the tower is in range to shoot.
    for (int i = 0; i < k ; i++) {
        auto it = lower_bound(h.begin(), h.end(), t[i]-w);
        if (it == h.end() || it->second > t[i] + w) continue;
        it->second--;
        combined_health--;
        if (it->second == 0) h.erase(it);
    }
}

int main() {
  cin >> n >> m >> k >> w;

  p.resize(m);
  t.resize(k);
  combined_health = 0;
  int h_i;
  for (int i = 0;i < m;i++) { cin >> p[i]; }
  for (int i = 0;i < m;i++) { cin >> h_i; h[h_i]++;}
  for (int i = 0;i < k;i++) { cin >> t[i]; }
    process();
  cout << combined_health << endl;
}
