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

void matrix(int A[][256], int a, int b, int y1, int x1, int y2, int x2) {
  int length = ((int)pow(2, a)) / 2;
  printf("current coordinates: (%d %d) => (%d %d)\n", y1, x1, y2, x2);
  if (a == 0) {
    A[y1][x1] = b;
    return;
  }
  if (a == 1) {
    printf(" filling A[%d][%d] with %d\n filling A[%d][%d] with %d\n filling "
           "A[%d][%d] with %d\n filling A[%d][%d] with %d\n",
           y1, x1, b, y1, x2 - 1, b - 1, y2 - 1, x1, b + 1, y2 - 1, x2 - 1,
           b);
    A[y1][x1] = b;
    A[y1][x2 - 1] = b - 1;
    A[y2 - 1][x1] = b + 1;
    A[y2 - 1][x2 - 1] = b;
    return;
  }
  matrix(A, a - 1, b, y1, x1, y1 + length, x1 + length);
  matrix(A, a - 1, b - 1, y1, x1 + length, y1+length, x2);
  matrix(A, a - 1, b + 1, y1+length, x1, y2, x1+length);
  matrix(A, a - 1, b , y1 + length, x1 + length, y2, x2);
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
