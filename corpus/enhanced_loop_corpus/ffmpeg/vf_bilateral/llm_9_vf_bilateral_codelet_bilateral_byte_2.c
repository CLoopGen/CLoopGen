#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int dst_linesize;
extern uint8_t *dst;
extern float *img_out_f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with strided iteration and simplified addressing
    int stride = 2;
    for (int i = 0; i < height; i += stride) {
        for (int j = 0; j < width; j++) {
            int linear_src = i * width + j;
            int linear_dst = j + i * dst_linesize;
            // Skip every other row, reducing total operations
            if (i < height && linear_src < width * height) {
                dst[linear_dst] = (uint8_t)img_out_f[linear_src];
            }
            // Process next row in same iteration if within bounds
            if (i + 1 < height) {
                dst[j + (i + 1) * dst_linesize] = (uint8_t)img_out_f[(i + 1) * width + j];
            }
        }
    }
}
