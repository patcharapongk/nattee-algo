#include <iostream>
#include <string>

int n, k;
std::string answer;

void gen_answer(int i, int consec_ones, int valid) {
    if (consec_ones >= k) {
        valid = 1;
    }
    if (n - i < k - consec_ones && !valid) {
        return;
    }
    if (i == n) {
        if (valid) std::cout << answer << "\n";
        return;
    }
    answer[i] = '0';
    gen_answer(i + 1, 0, valid);
    answer[i] = '1';
    gen_answer(i + 1, consec_ones + 1, valid);
}

int main(void) {
    std::cin >> n >> k;
    answer = std::string(n, '0');
    gen_answer(0, 0, 0);
    return 0;
}
