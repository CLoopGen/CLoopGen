#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a_work[8];
extern double alpha[7][7];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing consecutive elements, use a stride of 2 with bounds consideration
    int stride = 2;
    for (k = 0; k < 7 - 1 && (k + stride) < 6; k += stride) {
        if (a_work[k + 3] > a_work[k + 1] * alpha[k][k + 1])
            break;
    }
}
