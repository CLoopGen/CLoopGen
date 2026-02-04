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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *dst_ptr = dst;
    float *src_ptr = img_out_f;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            *dst_ptr++ = (uint8_t)(*src_ptr++);
        }
        dst_ptr += dst_linesize - width; // Adjust for stride at end of row
    }
}
