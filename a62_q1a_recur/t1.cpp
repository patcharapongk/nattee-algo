#include <iostream>
using namespace std;

int a, b;
int A[256][256];
int side;

void print_sq_matrix(int matrix[][256], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void matrix(int A[][256], int a, int b, int x1, int y1, int x2, int y2) {
  printf("x1, y1: %d,%d  |  x2, y2: %d,%d \n", x1, y1, x2, y2);
  int length = pow(2, a);
  --y2;
  --x2;
  if (a == 0) {
    A[y1][x1] = b;
    return;
  }
  if (a == 1) {
    A[y1][x1] = b;
    A[y1][x2] = b - 1;
    A[y2][x1] = b + 1;
    A[y2][x2] = b;
    return;
  }
  matrix(A, a - 1, b, x1, y1, x1 + length, y1 + length);
  matrix(A, a - 1, b - 1, x1, y1 + length, x2 - length, y2);
  matrix(A, a - 1, b + 1, x1 + length, y1 + length, x2, y2);
  matrix(A, a - 1, b, x1, y1 + length, x2 - length, y2);
}
void matrix(int A[][256], int a, int b) {
  side = (int)pow(2, a);
  printf("side length: %d\n", side);
  matrix(A, a, b, 0, 0, side, side);
}
int main() {
  cin >> a >> b;
  matrix(A, a, b);
  print_sq_matrix(A, side);
}
