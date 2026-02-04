#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height_new;
extern int width_new;
extern int i;
extern int j;
extern float *result;
extern float *result_converted;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We now iterate over the output array in row-major (consecutive) order
    int idx = 0;
    for (i = 0; i < width_new; i++) {
        for (j = 0; j < height_new; j++) {
            result_converted[idx] = result[j * width_new + i];
            idx++;
        }
    }
}
