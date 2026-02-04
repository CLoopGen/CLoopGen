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
    // Variant 1: Increased computational intensity with redundant arithmetic and unrolled inner loop by factor of 2
    for (int i = 0; i < height; i++) {
        int base_idx_dst = i * dst_linesize;
        int base_idx_img = i * width;
        for (int j = 0; j < width - 1; j += 2) {
            float val1 = img_out_f[base_idx_img + j];
            float val2 = img_out_f[base_idx_img + j + 1];
            // Add dummy arithmetic to increase computation per iteration
            val1 += 0.0001f; val1 -= 0.0001f;
            val2 += 0.0001f; val2 -= 0.0001f;
            dst[j + base_idx_dst] = (uint8_t)val1;
            dst[j + 1 + base_idx_dst] = (uint8_t)val2;
        }
        // Handle remaining element if width is odd
        if (width % 2 == 1) {
            dst[width - 1 + base_idx_dst] = (uint8_t)img_out_f[base_idx_img + width - 1];
        }
    }
}
