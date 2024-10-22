#include <stdio.h>

void __attribute__((noinline)) perm(int *x, int *y, int N, int a) {
    for (int i=0; i<N; i++) {
        int xidx;
        if (i&1) {
            xidx = i >> 2;
        } else {
            xidx = i ^ a;
        }
        y[i] = x[xidx];
    }
}

int main() {
  int N = 20;
  int a = 7;
  int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int y[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  perm(x, y, N, a);

  printf("y[0] = %d,\ty[1] = %d\n", y[0], y[1]);
  return 0;
}