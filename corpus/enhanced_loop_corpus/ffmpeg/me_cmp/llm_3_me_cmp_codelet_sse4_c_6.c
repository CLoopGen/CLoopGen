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
    uint8_t *p1 = pix1;
    uint8_t *p2 = pix2;
    int offset;
    for (i = 0; i < h; i++) {
        offset = i * stride;
        s += sq[p1[offset + 0] - p2[offset + 0]];
        s += sq[p1[offset + 1] - p2[offset + 1]];
        s += sq[p1[offset + 2] - p2[offset + 2]];
        s += sq[p1[offset + 3] - p2[offset + 3]];
    }
}
