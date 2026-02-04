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
    int row_offset1 = y * stride1;
    int row_offset2 = y * stride2;
    for (x = 0; x < w; x++) {
        int d = src1[x + row_offset1] - src2[x + row_offset2];
        ssd += d * d;
    }
}
}
