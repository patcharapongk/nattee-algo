#include <iostream>
#include <map>
#include <vector>

#define INPUT_UP_LIMIT 20
#define INPUT_LO_LIMIT 1
int n, m;
std::map<int, std::vector<int> > data;
using namespace std;

template <typename T>
void print_vector(const vector<T> &v) {
    for (const auto &x : v) std::cout << x << " ";
    std::cout << "\n";
}

void permu(vector<int> &v, int char_index, vector<bool> &used) {
    if (char_index == v.size()) {
        print_vector(v);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            if (data.find(i) != data.end()) {
                for (auto x : v) used[x] = 1;
            }
            v[char_index] = i;
            permu(v, char_index + 1, used);
            used[i] = 0;
            if (data.find(i) != data.end()) {
                for (auto x : v) used[x] = 0;
            }
        }
    }
}

int main(void) {
    std::cin >> n >> m;
    if (n < INPUT_LO_LIMIT || m < 0 || n > INPUT_UP_LIMIT ||
        m > INPUT_UP_LIMIT) {
        std::cerr << "n or m out of range\n";
        return 1;
    }

    // n is the permutation limit
    vector<int> v(n);
    vector<bool> used(n);

    if (m == 0) {
        permu(v, 0, used);
        return 0;
    }

    // m is the number of lines for before-after constraint
    int a, b;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        if (a < 0 || b < 0 || a > n - 1 || b > n - 1) {
            std::cerr << "a or b out of range";
            return 1;
        }
        data[b].push_back(a);
    }
    permu(v, 0 , used);
    return 0;
}
