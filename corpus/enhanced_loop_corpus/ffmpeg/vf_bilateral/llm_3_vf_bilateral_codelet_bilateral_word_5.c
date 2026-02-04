#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint16_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2, processing elements in two passes for better cache utilization or SIMD alignment
    // First pass: even indices
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j += 2)
            dst[j + i * dst_linesize] = img_out_f[i * width + j];
    }
    // Second pass: odd indices
    for (int i = 0; i < height; i++) {
        for (int j = 1; j < width; j += 2)
            dst[j + i * dst_linesize] = img_out_f[i * width + j];
    }
}
