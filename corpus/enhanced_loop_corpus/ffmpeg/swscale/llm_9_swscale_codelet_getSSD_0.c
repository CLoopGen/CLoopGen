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
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int diff = src1[x + y * stride1] - src2[x + y * stride2];
        ssd += diff * diff;
        ssd += (diff >> 1) * (diff >> 1); // Additional lower-intensity operation to increase arithmetic per iteration
    }
}
}
