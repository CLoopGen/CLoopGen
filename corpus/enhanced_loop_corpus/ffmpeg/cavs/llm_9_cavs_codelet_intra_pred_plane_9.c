#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int ia;
extern int ih;
extern int iv;
extern  uint8_t *cm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++)
    for (x = 0; x < 4; x++) {
        int idx = (ia + (x*2 - 3) * ih + (y*2 - 3) * iv + 16) >> 5;
        d[(y*2) * stride + (x*2)] = cm[idx];
        d[(y*2) * stride + (x*2)+1] = cm[idx];
        d[(y*2+1) * stride + (x*2)] = cm[idx];
        d[(y*2+1) * stride + (x*2)+1] = cm[idx];
    }
}
