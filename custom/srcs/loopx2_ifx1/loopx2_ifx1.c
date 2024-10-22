#include <stdio.h>

void __attribute__((noinline))  loopx2_ifx1(int *idx, int *x, int *y, int M, int N, int *a) {
  for (int i=0; i<M; i++) {
    int aa = a[i];
    for (int j=0; j<N; j++) {
      int xx = x[idx[j]];
      if ((xx >> i) & 1) {
        y[j] += aa * xx;
      }
    }
  }
}

int main() {
  int M = 4;
  int N = 8;
  int idx[8] = {7, 6, 5, 4, 3, 2, 1, 0};
  int x[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int y[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int a[4] = {1, 2, 3, 4};
  loopx2_ifx1(idx, x, y, M, N, a);

  printf("y[0] = %d,\ty[1] = %d\n", y[0], y[1]);
  return 0;
}