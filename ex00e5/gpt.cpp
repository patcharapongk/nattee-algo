#include <iostream>
#include <string>

int n, k;
std::string answer;

void gen_answer(int i, int consec_ones, bool valid) {
    // Update valid status if consecutive ones are enough
    if (consec_ones >= k) {
        valid = true;
    }

    // If not enough positions left to achieve k consecutive ones
    if (i > n - k && !valid) {
        return;
    }

    // Force 1's in the remaining positions if sequence is not yet valid
    if (i == n - k && !valid) {
        for (int j = i; j < n; j++) {
            answer[j] = '1';
        }
        std::cout << answer << "\n";
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

int main() {
    std::cin >> n >> k;
    answer = std::string(n, '0');
    gen_answer(0, 0, false);
    return 0;
}
