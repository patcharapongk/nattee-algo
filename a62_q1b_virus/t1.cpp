#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, k; 
vector<int> a;

std::string gen(int k, int reverse){
    if (k == 1) return "0 1 ";
    if (!reverse) return gen(k-1, 1);
    else return gen(k-1, 0);
} 

int main() {
    std::cin >> n >> k;
}
