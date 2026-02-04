#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix1;
extern uint8_t *pix2;
extern ptrdiff_t stride;
extern int h;
extern int s;
extern int i;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop and direct array indexing
    uint8_t *p1 = pix1;
    uint8_t *p2 = pix2;
    for (i = 0; i < h; i++) {
        s += sq[p1[0] - p2[0]];
        s += sq[p1[1] - p2[1]];
        s += sq[p1[2] - p2[2]];
        s += sq[p1[3] - p2[3]];
        // Access next four elements consecutively in memory
        s += sq[p1[4] - p2[4]];
        s += sq[p1[5] - p2[5]];
        s += sq[p1[6] - p2[6]];
        s += sq[p1[7] - p2[7]];
        p1 += stride;
        p2 += stride;
    }
}
