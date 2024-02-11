#include <iostream>

using namespace std;

int n, k;
int result[2][2];
int temp_result[2][2];
int amodk_base[2][2];
int a, b, c, d;

void print_sq_matrix(int matrix[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void write_to_matrix(int matrix[2][2], int a, int b, int c, int d) {
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
}

void fill_amodk_base(int a, int b, int c, int d, int k) {
    amodk_base[0][0] = a % k;
    amodk_base[0][1] = b % k;
    amodk_base[1][0] = c % k;
    amodk_base[1][1] = d % k;
}

void matrix_mod_k(int matrix[2][2], int k) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] %= k;
        }
    }
}

void matrix_multiply(int matrix1[2][2], int matrix2[2][2]) {
    temp_result[0][0] =
        matrix1[0][0] * matrix2[0][0] + matrix1[0][1] * matrix2[1][0];
    temp_result[0][1] =
        matrix1[0][0] * matrix2[0][1] + matrix1[0][1] * matrix2[1][1];
    temp_result[1][0] =
        matrix1[1][0] * matrix2[0][0] + matrix1[1][1] * matrix2[1][0];
    temp_result[1][1] =
        matrix1[1][0] * matrix2[0][1] + matrix1[1][1] * matrix2[1][1];
}

void recur(int matrix[][2], int k) {
    if (k == 1) return;
    // even case
    if (k % 2 == 0) {
        recur(matrix, k / 2);
        matrix_multiply(temp_result, temp_result);
        matrix_mod_k(temp_result, k);

    }
    // odd case
    else {
    }
}

int main() {
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    fill_amodk_base(a, b, c, d, k);

    return 0;
}
