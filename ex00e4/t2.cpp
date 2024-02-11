// 0 BLACK
// 1 WHITE
#include <iostream>

using namespace std;
vector<int> v;

template <typename T>
void print_vector(const vector<T> &v) {
    for (const auto &x : v) std::cout << x << " ";
    std::cout << "\n";
}

void gen_barcode(int length_limit, int ones_limit, int ones, int zeros) {
    if (ones+zeros == length_limit) {
       print_vector(v);
       return;
    }
    v[ones+zeros] = 0;
    gen_barcode(length_limit, ones_limit, ones+1, zeros+1);
    v[ones+zeros] = 1;
    gen_barcode(length_limit, ones_limit, ones+1, zeros+1);
}


int main() {
    int A, B;
    std::cin >> A >> B;
    if (A < 0 || B < 0 || A > 20 || B > 20) {
        std::cerr << "A or B out of range\n";
        return 1;
    }
    v.resize(B);
    gen_barcode(B, A, 0, 0);
    return 0;
}
