#include <iostream>
#include <ostream>
const int MAX_ARRAY_SIZE = 100000;
int N, M;
int A[MAX_ARRAY_SIZE];

int get_inputs() {
    std::cin >> N >> M;
    if (N < 1 || N > MAX_ARRAY_SIZE  || M < 1 || M > MAX_ARRAY_SIZE) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    return 0;
}
void fill_array() {
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
}

int inv_lower_bound(int* arr, int target, int left, int right) {
    if (left > right) return arr[left];
    int mid = (right+left) / 2;
    if (target >= arr[mid]) return inv_lower_bound(arr, target, mid+1, right);
    else return inv_lower_bound(arr, target, left, mid);
}


int main(void) {
    if (get_inputs()) return 1;
    fill_array();

    int target;
    for (int i = 0; i < M; i++) {
        std::cin >> target;
        std::cout << inv_lower_bound(A, target, 0, N-1) << std::endl;
    }
    return 0;
}
