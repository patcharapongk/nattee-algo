#include <vector>
#include <map>
#include <iostream>

const int N_LIMIT = 10e6;
int p[10] = {0};

int main(void) {
    int n, m, k, w;
    std::cin >> n >> m >> k >> w;
    if (n < 0 || n > N_LIMIT) {
        std::cerr << "n out of range\n";
        return 1;
    }
    if (w < 0 || w > n) {
        std::cerr << "w out of range or execeeded n\n";
        return 1;
    } 

    // n limits the road length
    // m limits the monster counts 
    // --> p(m) = monsters' positions
    // --> h(m) = monsters' healths
    // k limits the tower counts
    // w limits the range in which the tower can shoot
    // --> [x-w, x+w] is the range for the tower on xth position.

    std::map<int, int> p;
    std::vector<int> h(m);
    // p (key,val) ==> (position, monster_counts)
    int p_i;
    for (int i = 0; i < m; i++) {
        std::cin >> p_i;
        
        if (p_i < 1 || p_i > n) {
            std::cerr << "p[i] out of range\n"; return 1;
        } 
        p[p_i]++;
    }

    // h[i] is the monster power for the ith monster.
    int h_i;
    for (int i = 0; i < m; i++) {
        std::cin >> h_i;
        h[i] = h_i;
    }

    // t[i] is the tower position on the road [1..n]
    std::vector<int> t(k);
    int t_i;
    for (int i = 0; i < k; i++) {
        std::cin >> t_i;
        t[i] = t_i;
    }

    /* -------------- PROCESS ---------------*/ 




    return 0;
}
