#include <stdio.h>

void __attribute__((noinline))  saxpy_if(int *x, int *y, int N, int a) {
    for (int i=0 ; i<N ; i++) {
        int dy;
        int xx = x[i];
        if (i & 1) dy = a*xx;
        else dy = xx;
        y[i] += dy;
    }
}

int main() {
  int N = 20;
  int a = 2;
  int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
               11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int y[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  saxpy_if(x, y, N, a);

  printf("y[0] = %d,\ty[1] = %d\n", y[0], y[1]);
  return 0;
}