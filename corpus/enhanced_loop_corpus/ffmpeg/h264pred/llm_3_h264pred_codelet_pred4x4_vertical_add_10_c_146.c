#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *p0 = pix;
    uint16_t *p1 = pix + stride;
    uint16_t *p2 = pix + 2 * stride;
    uint16_t *p3 = pix + 3 * stride;
    uint16_t *p4 = pix + 4 * stride;

    for (i = 0; i < 4; i++) {
        uint16_t v = p0[i];
        p1[i] = v += block[0];
        p2[i] = v += block[4];
        p3[i] = v += block[8];
        p4[i] = v + block[12];
    }
}
