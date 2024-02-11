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
   if (target < A[0]) return -1;
   if (left == right) return left;
    int mid = (left+right) / 2;
   if (target > arr[mid]) return bsearch(arr, mid+1, right, target);
   if (target <= arr[mid]) return bsearch(arr, left, mid, target);
}

void print_int(int n) { std::cout << n << " "; }
void println() { std::cout << "\n"; }

int process_answer(int index, int target) {
    if (index == -1) return -1;
    if (target == A[index]) return index;
    if (target >  A[index]) return index;
    else return index - 1;
}

int main(void) {
    if (get_inputs()) return 1;
    fill_array();

    int target;
    for (int i = 0; i < M; i++) {
        std::cin >> target;
        int index = bsearch(A, 0, N-1, target);
        int ans = process_answer(index, target);
        print_int( ans == -1 ? -1 : A[ans]);
       println();
            }
  
    return 0;
}
