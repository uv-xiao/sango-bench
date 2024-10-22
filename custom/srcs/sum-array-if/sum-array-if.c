#include <stdio.h>

int __attribute__((noinline)) sum_array(int* input, int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    int x = input[i];
    int z;
    if (x & 1) {
        sum += x ^ 1;
    } else {
        sum += x >> 1;
    }
  }
  return sum;
}

int main() {
  int input[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int sum = sum_array(input, 20);
  printf("Sum = %d\n", sum);

  return 0;
}
