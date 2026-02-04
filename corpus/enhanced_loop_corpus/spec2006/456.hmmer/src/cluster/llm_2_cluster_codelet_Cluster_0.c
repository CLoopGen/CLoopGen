#include <stdio.h>

#include <inttypes.h>

extern int N;
extern int *coord;
extern int col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    int stride = 2;
    int limit = N - (N % stride); // Make sure we don't overflow
    for (col = 0; col < limit; col += stride) {
        coord[col] = col;
        if (col + 1 < N) {
            coord[col + 1] = col + 1;
        }
    }
    // Handle remaining element if N is odd
    if (limit < N) {
        coord[N - 1] = N - 1;
    }
}
