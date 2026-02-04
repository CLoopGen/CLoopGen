#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t src_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++, dst += dst_linesize, src++) {
        // Reverse inner loop to change data access pattern and eliminate forward loop-carried dependency
        for (x = w - 1; x >= 0; x--) {
            dst[x] = src[x * src_linesize];
        }
    }
}
