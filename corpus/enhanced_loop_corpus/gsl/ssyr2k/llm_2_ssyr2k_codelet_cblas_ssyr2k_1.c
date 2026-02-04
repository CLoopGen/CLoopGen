#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of accessing C[ldc*i + j] for j <= i (lower triangular), we reorganize to write in column-major-like consecutive pattern
    // We iterate by column first, then row, ensuring writes are consecutive when possible
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            C[ldc * i + j] = 0.;
        }
    }
}
