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
    // Variant 2: Strided memory access with reversed traversal and stride of 2
    float *img_base = img_out_f + h1 * width;
    float *map_base = map_factor_b + h1 * width;
    int k = 0;
    // Process elements in reverse order with stride 2 for non-sequential access pattern
    for (int x = (width % 2 == 0) ? width - 2 : width - 1; x >= 0; x -= 2) {
        int idx = x;
        img_base[idx] = 0.5F * (img_base[idx] + ypy[k++]) / map_base[idx];
        if (x > 0) {
            idx = x - 1;
            img_base[idx] = 0.5F * (img_base[idx] + ypy[k++]) / map_base[idx];
        }
    }
}
