#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern ptrdiff_t width;
extern int height;
extern int i;
extern int j;
extern uint8_t prev;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    for (j = 0; j < height; j++) {
        for (i = 0; i + 1 < width; i += 2) {
            uint8_t curr0 = src[i];
            uint8_t curr1 = src[i + 1];
            *dst++ = curr0 - prev;
            *dst++ = curr1 - curr0;
            prev = curr1;
        }
        if (i < width) {
            uint8_t curr = src[i];
            *dst++ = curr - prev;
            prev = curr;
        }
        src += stride;
    }
}
