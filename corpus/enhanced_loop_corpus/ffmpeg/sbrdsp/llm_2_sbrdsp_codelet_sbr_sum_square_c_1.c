#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float (*x)[2];
extern int n;
extern float sum0;
extern float sum1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    // Instead of accessing x[i][0] and x[i][1] with array indexing, use a flat pointer
    // to traverse elements in consecutive order for better spatial locality.

    float *ptr = &x[0][0];
    int limit = n * 2;
    for (i = 0; i < limit; i += 4) {
        sum0 += ptr[i + 0] * ptr[i + 0];
        sum1 += ptr[i + 1] * ptr[i + 1];
        sum0 += ptr[i + 2] * ptr[i + 2];
        sum1 += ptr[i + 3] * ptr[i + 3];
    }
}
