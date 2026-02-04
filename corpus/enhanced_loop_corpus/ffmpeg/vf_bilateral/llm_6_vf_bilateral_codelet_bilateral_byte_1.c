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
    for (int x = 0; x < width; x++) {
        int idx = h1 * width + x;
        float temp_sum = img_out_f[idx] + ypy[x];
        img_out_f[idx] = 0.5F * temp_sum / map_factor_b[idx];
    }
}
