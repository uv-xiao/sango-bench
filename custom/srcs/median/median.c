
#include <stdio.h>

void median( int n, int input[], int results[] )
{
  int A, B, C, i;

  // Zero the ends
  results[0]   = 0;
  results[n-1] = 0;

  // Do the filter
  for ( i = 1; i < (n-1); i++ ) {

    A = input[i-1];
    B = input[i];
    C = input[i+1];

    int D;
    
    if ( A < B ) {
      if ( B < C )
        D = B;
      else if ( C < A )
        D = A;
      else
        D = C;
    }

    else {
      if ( A < C )
        D = A;
      else if ( C < B )
        D = B;
      else
        D = C;
    }

    results[i] = D;

  }

}

int main() {

  int n = 10;

  int input[10] = {1112, 232, 122, 3923, 321, 23, 223, 2324, 232, 232};
  int results[10];

  median(n, input, results);

  printf("%d %d %d\n", results[1],  results[2], results[3]);
  return 0;
}