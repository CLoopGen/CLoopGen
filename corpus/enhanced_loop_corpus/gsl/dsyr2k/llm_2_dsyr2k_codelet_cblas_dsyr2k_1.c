#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the loop order
    // Instead of accessing C[ldc*i + j] with j <= i (upper triangular), we process column-wise
    // and ensure consecutive writes when possible by changing iteration order.
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            C[ldc * i + j] = 0.;
        }
    }
}
