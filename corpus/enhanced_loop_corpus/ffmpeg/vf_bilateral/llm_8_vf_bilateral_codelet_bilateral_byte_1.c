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
for (int x = 0, k = 0; x < width; x += 2) {
    int idx1 = h1 * width + x;
    img_out_f[idx1] = 0.5F * (img_out_f[idx1] + ypy[k++]) / map_factor_b[idx1];
    if (x + 1 < width) {
        int idx2 = h1 * width + x + 1;
        img_out_f[idx2] = 0.5F * (img_out_f[idx2] + ypy[k++]) / map_factor_b[idx2];
    }
}
}
