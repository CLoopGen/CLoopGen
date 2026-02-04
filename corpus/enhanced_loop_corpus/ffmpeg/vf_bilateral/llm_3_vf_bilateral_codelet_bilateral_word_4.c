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
    // Variant 2: Strided memory access (access every 2nd element, then fill in reverse order)
    // This changes access pattern to non-sequential and reverse index mapping
    int stride = 2;
    int k = 0;
    // First pass: even indices
    for (int x = 0; x < width; x += stride) {
        int idx = h1 * width + x;
        img_out_f[idx] = 0.5F * (img_out_f[idx] + ypy[k++]) / map_factor_b[idx];
    }
    // Second pass: odd indices in reverse order
    for (int x = ((width - 1) | 1); x >= 0; x -= stride) {
        if (x < width && x % 2 == 1) {
            int idx = h1 * width + x;
            img_out_f[idx] = 0.5F * (img_out_f[idx] + ypy[k++]) / map_factor_b[idx];
        }
    }
}
