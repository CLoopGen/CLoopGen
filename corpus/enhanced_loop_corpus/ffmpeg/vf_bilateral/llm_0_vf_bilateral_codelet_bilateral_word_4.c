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
        for (int h = 0; h <= h1; h++) {
            if (h == h1) {
                int idx = h * width + x;
                int k = x;
                img_out_f[idx] = 0.5F * (img_out_f[idx] + ypy[k]) / map_factor_b[idx];
            }
        }
    }
}
