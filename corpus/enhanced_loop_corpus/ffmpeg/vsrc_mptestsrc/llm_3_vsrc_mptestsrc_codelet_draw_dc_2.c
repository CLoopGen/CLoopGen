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
    // Variant 2: Strided memory access by iterating over memory in vertical stripes (column-major)
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            dst[x + y * dst_linesize] = color;
        }
    }
}
