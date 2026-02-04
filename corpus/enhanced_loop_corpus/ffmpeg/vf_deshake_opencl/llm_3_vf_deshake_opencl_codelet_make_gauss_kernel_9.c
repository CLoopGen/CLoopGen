#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *gauss_kernel;
extern float length;
extern float gauss_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (int i = (int)length - 1; i >= 0; --i) {
        gauss_kernel[i] /= gauss_sum;
    }
}
