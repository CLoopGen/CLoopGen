#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D iteration into a 1D linear pass
    uint16_t *src_ptr = src;
    for (int i = 0; i < h * w; i++) {
        histogram[src_ptr[i]] += 1;
    }
}
