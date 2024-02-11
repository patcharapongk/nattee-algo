#include <iostream>

using namespace std;

int usable[] = {1, 11, 111};
int global_min = 1000000;

void dc(int target, int ones_count) {
    cout << target << endl;
    if (target < 0) return;

    if (target == 0) {
        if (ones_count < global_min) {
            global_min = ones_count;
            cout << "New min: " << global_min << endl;
            return;
        }
    }

    for (int i = 0; i < 3; ++i) {
        dc(target - usable[i], ones_count + i + 1);
    }
}

int main() {
    dc(121,  0);
    cout << "Min: " << global_min << endl;
    return 0;
}

