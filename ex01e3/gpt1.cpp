
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


int bsearch(int* arr, int left, int right, int target) {
    if (left > right) 
        return right;  // Return the right pointer when the search ends

    int mid = left + (right - left) / 2;

    if (target >= arr[mid])
        return bsearch(arr, mid + 1, right, target);
    else
        return bsearch(arr, left, mid - 1, target);
}

int main(void) {
    if (get_inputs()) return 1;
    fill_array();

    int target;
    for (int i = 0; i < M; i++) {
        std::cin >> target;
        int index = bsearch(A, 0, N - 1, target);

        if (index == -1 || A[index] > target)  // Check for no such element or greater value
            std::cout << -1 << std::endl;
        else
            std::cout << A[index] << std::endl;
    }
    return 0;
}
