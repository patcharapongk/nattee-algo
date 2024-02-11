#include <iostream>
#include <vector>

using namespace std;

int barcode_length, barcode_ones_limit;
vector<int> ans;

void print_vector(const vector<int> &v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}

void gen_barcode(int n, int barcode_ones) {
    if (n == barcode_length) {
        print_vector(ans);
        return;
    }
   
    if (barcode_ones > barcode_ones_limit) return;

    ans[n] = 0;
    gen_barcode(n + 1, barcode_ones);
    ans[n] = 1;
    gen_barcode(n + 1, barcode_ones + 1);
}

int main(void) {
    cin >> barcode_ones_limit >> barcode_length;
    ans.resize(barcode_length);
    gen_barcode(0, 0);
    return 0;
}
