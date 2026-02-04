#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *src_line = src;
    uint8_t *dst_line = dst;
    for (i = 0; i < height; i++) {
        uint8_t *src_ptr = src_line;
        uint8_t *dst_ptr = dst_line;
        for (j = 0; j < width; j++) {
            dst_ptr[j] = ((3 * src_ptr[j] + 2 * src_ptr[j + 1] + 
                          4 * src_ptr[j + stride] + 3 * src_ptr[j + stride + 1] + 6) * 2731) >> 15;
        }
        src_line += stride;
        dst_line += stride;
    }
}
