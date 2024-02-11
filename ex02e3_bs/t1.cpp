#include <iostream>

const int MAX_LIMIT = 1000000;
int N, M;
int arr[MAX_LIMIT];

int get_inputs();
int fill_array();
void play();
int find_arr(int* arr, int target, int left, int right);
int find_arr(int* arr, int target);

int main(void) {
    if (!get_inputs()) return 1;
    if (!fill_array()) return 1;
    printf("N: %d, M: %d\n", N, M);
    play();
    return 0;
}

int find_arr(int* arr, int target, int left, int right) {
       if (left == right) {
            if (target == arr[left]) return left;
            else {
                return left -1 >= 0 ? left -1 : -1;
            }
       }

           int mid = (left + right) / 2;
    if (target < arr[mid]) return find_arr(arr, target, left, mid);
    else return find_arr(arr, target, mid+1, right);   

}
int find_arr(int* arr, int target) {
    return find_arr(arr, target, 0, N-1);
}

void play() {
    int query;
    for (int i = 0; i < M; ++i) {
        std::cin >> query;
        printf("query: %d\n", query);
        std::cout << find_arr(arr, query) << std::endl;
    }
}

// 0 means invalid
int get_inputs() {
    std::cin >> N >> M;
    if (N < 1 || N > MAX_LIMIT || M < 1 || M > MAX_LIMIT) {
        std::cerr << "N or M out of range\n";
        return 0;
    }
    return 1;
}

// 0 means invalid
int fill_array() {
    int input;
    for (int i = 0; i < N; ++i) {
        std::cin >> input;
        if (input <= 0) {
            std::cerr << "Input given is less than or equals to 0\n";
            return 0;
        }
    }
    return 1;
}
