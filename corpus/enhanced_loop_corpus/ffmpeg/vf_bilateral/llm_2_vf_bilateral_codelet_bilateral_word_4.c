#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern float *img_out_f;
extern float *map_factor_b;
extern float *ypy;
extern int h1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    float *img_ptr = img_out_f + h1 * width;
    float *ypy_ptr = ypy;
    float *map_ptr = map_factor_b + h1 * width;
    for (int x = 0; x < width; x++) {
        img_ptr[x] = 0.5F * (img_ptr[x] + ypy_ptr[x]) / map_ptr[x];
    }
}
