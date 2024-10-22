#include <stdio.h>

void __attribute__((noinline))  saxpy(int *x, int *y, int N, int a, int b, int c) {
    for (int i=0 ; i<N ; i++) {
      y[i] += (a*x[i] + (b^i)) ^ (c+i);
    }
}

int main() {
  int N = 20;
  int a = 2;
  int b = 63;
  int c = 1;
  int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int y[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  saxpy(x, y, N, a, b, c);

  printf("y[0] = %d,\ty[1] = %d\n", y[0], y[1]);
  return 0;
}