#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_stride;
extern  uint8_t *src;
extern int src_stride;
extern int w;
extern int h;
extern int x;
extern int y;
extern int pel;
extern int contrast;
extern int brightness;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (y = 0; y < h; y++) {
        uint8_t *src_ptr = src_row;
        uint8_t *dst_ptr = dst_row;
        for (x = 0; x < w; x++) {
            pel = ((*src_ptr * contrast) >> 12) + brightness;
            if (pel & ~255)
                pel = (-pel) >> 31;
            *dst_ptr = pel;
            src_ptr++;
            dst_ptr++;
        }
        src_row += src_stride;
        dst_row += dst_stride;
    }
}
