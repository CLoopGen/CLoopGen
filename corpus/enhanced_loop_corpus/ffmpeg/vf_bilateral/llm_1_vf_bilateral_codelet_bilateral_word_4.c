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
    if (width > 0) {
        int idx = h1 * width;
        int k = 0;
        for (int block = 0; block < width; block += 8) {
            int end = (block + 8 < width) ? block + 8 : width;
            for (int x = block; x < end; x++) {
                int local_idx = idx + x;
                img_out_f[local_idx] = 0.5F * (img_out_f[local_idx] + ypy[k++]) / map_factor_b[local_idx];
            }
        }
    }
}
