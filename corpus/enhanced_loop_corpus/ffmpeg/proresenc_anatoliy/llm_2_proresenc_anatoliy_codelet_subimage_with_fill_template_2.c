#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern unsigned int dst_width;
extern unsigned int dst_height;
extern int i;
extern int j;
extern uint16_t *last_line;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing one row at a time in order, access elements with a stride
    // Here we process every second element in a row first, then the odd indices (unroll by 2)
    for (; i < dst_height; i++) {
        for (j = 0; j < dst_width; j += 2) {
            if (j + 1 < dst_width) {
                dst[j]     = last_line[j];
                dst[j + 1] = last_line[j + 1];
            } else {
                dst[j] = last_line[j];
            }
        }
        dst += dst_width;
    }
}
