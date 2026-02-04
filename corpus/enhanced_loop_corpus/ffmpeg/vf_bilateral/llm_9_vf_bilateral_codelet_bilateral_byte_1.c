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
float factor = 0.25F;
for (int x = 0, k = 0; x < width; x++) {
    int idx = h1 * width + x;
    float temp_sum = img_out_f[idx] + ypy[k++];
    float normalized = temp_sum / map_factor_b[idx];
    img_out_f[idx] = factor * normalized + 0.75F * normalized;
}
}
