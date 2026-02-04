#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cheb24[25];
extern double moment[25];
extern double res24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t i;
    double temp_res = 0.0;
    // Process elements in strides of 2, forward traversal
    for (i = 0; i < 25; i += 2) {
        temp_res += cheb24[i] * moment[i];
        if (i + 1 < 25) {
            temp_res += cheb24[i + 1] * moment[i + 1];
        }
    }
    res24 += temp_res;
}
