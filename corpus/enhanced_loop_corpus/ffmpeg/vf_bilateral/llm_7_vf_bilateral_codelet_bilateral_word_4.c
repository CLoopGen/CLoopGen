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
    float *base_img = &img_out_f[h1 * width];
    float *base_ypy = &ypy[0];
    float *base_factor = &map_factor_b[h1 * width];
    for (int x = 0; x < width; x++) {
        float sum_val = base_img[x] + base_ypy[x];
        float result = 0.5F * sum_val / base_factor[x];
        base_img[x] = result;
    }
}
