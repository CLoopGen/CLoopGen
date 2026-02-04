#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int stride;
extern int i;
extern int tblk[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with local accumulation buffer
    uint8_t temp[16];
    for (int j = 0; j < 4; j++) {
        int base = j * 4;
        int t0 = tblk[base + 0], t1 = tblk[base + 1], t2 = tblk[base + 2], t3 = tblk[base + 3];
        temp[j * 4 + 0] = ((5 * (t0 + t1 + t2) + 2 * t3) + 32) >> 6;
        temp[j * 4 + 1] = ((5 * (t0 - t2 - t3) + 2 * t1) + 32) >> 6;
        temp[j * 4 + 2] = ((5 * (t0 - t2 + t3) - 2 * t1) + 32) >> 6;
        temp[j * 4 + 3] = ((5 * (t0 - t1 + t2) - 2 * t3) + 32) >> 6;
    }
    // Write out in strided fashion as originally intended
    for (int j = 0; j < 4; j++) {
        dst[0] = temp[j * 4 + 0];
        dst[1] = temp[j * 4 + 1];
        dst[2] = temp[j * 4 + 2];
        dst[3] = temp[j * 4 + 3];
        dst += stride;
    }
}
