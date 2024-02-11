#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

template <typename T>
void print_vector(const vector<T> &v) {
    for (const auto &x : v) std::cout << x << " ";
    std::cout << "\n";
}

void gen_barcode(int ones_limit, int ones, int zeros) {
    if (ones + zeros == v.size() ) {
        if (ones == ones_limit) print_vector(v);
        return;
    }
    v[ones + zeros] = 0;
    gen_barcode(ones_limit, ones, zeros + 1);
    v[ones + zeros] = 1;
    gen_barcode(ones_limit, ones + 1, zeros);
}

int main(void) {
    int A, B;
    std::cin >> A >> B;
    if (A < 0 || A > 20 || B < 0 || B > 20) {
        std::cerr << "A or B out of range\n";
        return 1;
    }
    v.resize(B);
    gen_barcode(A, 0, 0);
    return 0;
}
