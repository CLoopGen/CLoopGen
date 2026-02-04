#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y_outer, y_inner;
    int total_iterations = height * 2;
    for (y_outer = 0; y_outer < height; y_outer++) {
        for (y_inner = 0; y_inner < 2; y_inner++) {
            y = (y_outer * 2 + y_inner);
            if (y >= height) break;
            dst += stride / 2;
            src += stride / 2;
        }
    }
    y = height;
    dst = dst - (height * stride / 2) + (height * stride);
    src = src - (height * stride / 2) + (height * stride);
}
