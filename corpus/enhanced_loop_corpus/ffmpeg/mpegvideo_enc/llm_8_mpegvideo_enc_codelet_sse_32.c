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
    for (x = 0; x < w; x += 2) {
        acc += sq[src1[x + y * stride] - src2[x + y * stride]];
        if (x + 1 < w) {
            acc += sq[src1[x + 1 + y * stride] - src2[x + 1 + y * stride]];
        }
    }
}
}
