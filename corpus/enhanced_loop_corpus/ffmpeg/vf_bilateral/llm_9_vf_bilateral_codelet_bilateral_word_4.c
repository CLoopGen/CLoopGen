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
    int idx = h1 * width + x;
    float sum = img_out_f[idx] + ypy[k++];
    float avg = 0.5F * sum;
    float factor = map_factor_b[idx] + 1e-6F;
    img_out_f[idx] = avg / factor;
    img_out_f[idx] *= (img_out_f[idx] > 0.1F) ? 1.0F : 1.2F;
}
}
