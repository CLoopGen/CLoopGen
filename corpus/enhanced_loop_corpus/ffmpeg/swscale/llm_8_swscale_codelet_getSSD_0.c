#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int w;
extern int h;
extern int x;
extern int y;
extern uint64_t ssd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 2) {
        int d1 = src1[x + y * stride1] - src2[x + y * stride2];
        int d2 = src1[(x+1) + y * stride1] - src2[(x+1) + y * stride2];
        int d3 = src1[x + (y+1) * stride1] - src2[x + (y+1) * stride2];
        int d4 = src1[(x+1) + (y+1) * stride1] - src2[(x+1) + (y+1) * stride2];
        ssd += d1 * d1 + d2 * d2 + d3 * d3 + d4 * d4;
    }
}
}
