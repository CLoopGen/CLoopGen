#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src1;
extern uint8_t *src2;
extern int w;
extern int h;
extern int stride;
extern  uint32_t *sq;
extern int acc;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    x = 0;
    acc += sq[src1[x + y * stride] - src2[x + y * stride]];
    x = 1;
    for (; x < w; x++) {
        acc += sq[src1[x + y * stride] - src2[x + y * stride]];
    }
}
}
