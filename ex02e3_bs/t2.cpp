#include <iostream>
int N, M;
int arr[1000000] = {0};
int target;

int bsearch_r(int l, int r) {
    if (target > arr[N-1]) return N-1;
    if (target < arr[0]) return -1;
    if (l == r) {
        return (target == arr[l]) ? l : l-1;
    }
    int mid = (r+l) >> 1;
    if (target >= arr[mid]) return bsearch_r(mid+1, r);
    else return bsearch_r(l, mid);
}

int main(int argc, char** argv) {
    std::cin >> N >> M;
    for (int i = 0 ; i < N ; ++i) std::cin >> arr[i];

    for (int i = 0 ; i < M ; ++i) {
        std::cin >> target;
        std::cout << bsearch_r(0, N-1) << std::endl;
    }

}
