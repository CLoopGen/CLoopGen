#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  unsigned int color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_elements = b_w * b_h;
    for (x = 0; x < total_elements; x++) {
        int iy = (x >> 6) % b_h;
        int ix = (x & 63) % b_w;
        dst[ix + iy * stride] = color ^ (x & 1 ? 0xFF : 0x00);
    }
}
