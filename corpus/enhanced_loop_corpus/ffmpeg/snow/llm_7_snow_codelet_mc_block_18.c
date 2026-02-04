#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int b_w;
extern int b_h;
extern int x;
extern int y;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int a;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset1 = 0, offset2 = 0, dst_offset = 0;
    for (y = 0; y < b_h; y++) {
        for (x = 0; x < b_w; x++) {
            dst[dst_offset + x] = (a * src1[offset1 + x] + b * src2[offset2 + x] + 4) >> 3;
        }
        offset1 += stride1;
        offset2 += stride2;
        dst_offset += stride;
    }
}
