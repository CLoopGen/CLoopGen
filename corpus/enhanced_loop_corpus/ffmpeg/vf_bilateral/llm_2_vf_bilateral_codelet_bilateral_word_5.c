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
    // Variant 1: Consecutive memory access by transposing the iteration order to access dst in a more sequential pattern
    // This variant reorders computation to improve spatial locality in dst, assuming dst_linesize >= width
    for (int j = 0; j < width; j++)
        for (int i = 0; i < height; i++)
            dst[j + i * dst_linesize] = img_out_f[i * width + j];
}
