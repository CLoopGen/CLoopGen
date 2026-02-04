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
    // Variant 2: Consecutive memory access by transposing the iteration order
    // Flatten the loop and traverse in column-major-like order to improve spatial locality
    int idx;
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            idx = ldc * i + j;
            C[idx] = 0.;
        }
    }
}
