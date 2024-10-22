#include "dataset.h"

void __attribute__((noinline)) spmv(int n_row, const int *val, const int *idx,
                                    const int *x, const int *ptr, int *y) {
  for (int i = 0; i < n_row; i++) {
    int k = 0;
    int sum = 0;
    for (k = ptr[i]; k < ptr[i + 1]; k++)
      if (val[k] & 1) {
        sum += val[k] * x[idx[k]];
      }
    y[i] = sum;
  }
}

int main() {
  int y[R];

  spmv(R, val, idx, x, ptr, y);

  return 0;
}