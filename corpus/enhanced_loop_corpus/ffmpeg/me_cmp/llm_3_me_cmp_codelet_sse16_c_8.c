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
    int offset[16];
    for (int j = 0; j < 16; j++) {
        offset[j] = j;
    }
    for (i = 0; i < h; i++) {
        for (int j = 0; j < 16; j++) {
            int idx = offset[j];
            s += sq[pix1[idx] - pix2[idx]];
        }
        pix1 += stride;
        pix2 += stride;
    }
}
