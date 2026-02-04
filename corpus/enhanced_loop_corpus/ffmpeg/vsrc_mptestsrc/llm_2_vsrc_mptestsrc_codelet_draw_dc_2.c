#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern int color;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *ptr = dst;
    for (int i = 0; i < h; i++) {
        uint8_t *row = ptr + i * dst_linesize;
        for (int j = 0; j < w; j++) {
            row[j] = color;
        }
    }
}
