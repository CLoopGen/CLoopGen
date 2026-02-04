#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *sample_noise;
extern double temp[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle all 15 elements
    int i;
    for (i = 0; i < 15; i += 2) {
        temp[i] = sample_noise[i];
    }
    // Handle remaining element if any (when i == 14, next would be 16 which is out of bounds)
    if (i - 2 == 13) {
        temp[14] = sample_noise[14];
    }
}
