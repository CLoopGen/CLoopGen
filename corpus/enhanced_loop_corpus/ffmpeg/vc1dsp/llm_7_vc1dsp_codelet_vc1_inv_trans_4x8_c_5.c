#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int16_t *src;
extern int16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
t1 = 0; t2 = 0; t3 = 0; t4 = 0;
for (i = 0; i < 8; i++) {
    int16_t temp_src0 = src[0], temp_src1 = src[1], temp_src2 = src[2], temp_src3 = src[3];
    t1 = 17 * (temp_src0 + temp_src2) + 4 + (t1 & 0x7); // Introduce WAW and loop-carried dependency via t1 reuse
    t2 = 17 * (temp_src0 - temp_src2) + 4 + (t2 >> 3); // Loop-carried dep on t2
    t3 = 22 * temp_src1 + 10 * temp_src3 + (t3 & t1);  // RAW: uses updated t1
    t4 = 22 * temp_src3 - 10 * temp_src1 + (t3 >> 2);  // WAR-like ordering preserved, depends on new t3
    dst[0] = (t1 + t3) >> 3;
    dst[1] = (t2 - t4) >> 3;
    dst[2] = (t2 + t4) >> 3;
    dst[3] = (t1 - t3) >> 3;
    src += 8;
    dst += 8;
}
}
