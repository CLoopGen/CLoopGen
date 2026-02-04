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
    // Variant 2: Strided memory access with stride of 2, unrolling every other element
    // Processes elements with a fixed stride pattern across rows, skipping every other column
    // Maintains lower triangular structure but accesses memory with larger stride
    for (i = 0; i < N; i++) {
        for (j = 0; j <= i; j += 2) {
            C[ldc * i + j] = 0.;
            if (j + 1 <= i) {
                C[ldc * i + (j + 1)] = 0.;
            }
        }
    }
}
