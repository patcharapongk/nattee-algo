#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int k;
int size_limit;
vector<int> v;

template <typename T>
void print_vector(vector<T> v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void gen(int k, int n, int left, int right) {
    if (n == 0) {
        print_vector(v);
        return;
    }   
    
}

void gen(int k) {
    gen(k, n, 0, size_limit-1);
}

int main() {
    std::cin >> k;
    size_limit = pow(2, k);
    v.resize(size_limit);
    gen(k);
}
