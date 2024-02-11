#include <iostream>
#include <vector>
std::vector<int> v(3);

template <typename T>
void print_vector(std::vector<T> &v) {
    for (const auto &x : v) std::cout << x << " ";
    std::cout << "\n";
}

void combi(int n) {
    if (n == v.size()) { print_vector(v); return;}
    v[n] = 0;
    combi(n+1);
    v[n] = 1;
    combi(n+1);
}


int main(void) {
    combi(0); 
    return 0;
}
