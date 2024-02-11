#include <iostream>

int X, N, K;
int mod_expo(int x, int n, int k) {
    // x ^ n mod k == (x mod n/2) * (x mod n/2) mod k
    if (n == 1) return x % k;
    int temp = mod_expo(x, n/2, k);
    if (n % 2 == 0) return ( temp * temp ) % k;
    else return ((temp * temp) % k * x) % k;
 
}

int main() {
    std::cin >> X >> N >> K;
    std::cout << mod_expo(X, N, K) << std::endl;
}
