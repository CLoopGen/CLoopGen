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
for (int x = 0, k = 0; x < width; x++) {
    if (map_factor_b[h1 * width + x] != 0.0F) {
        int idx = h1 * width + x;
        img_out_f[idx] = 0.5F * (img_out_f[idx] + ypy[k++]) / map_factor_b[idx];
    }
}
}
