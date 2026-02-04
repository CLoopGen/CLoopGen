#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *flags;
extern int i;
extern  int32_t *src;
extern int32_t *dst;
extern int t0;
extern int t1;
extern int t2;
extern int t3;
extern int t4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    t0 = (src[0]) - (src[8]);
    t1 = (src[0]) + (src[8]);
    t2 = (t0);
    t0 = (((src[4]) + (src[12]) * 2 + 2) >> 2) + (src[4]);
    t3 = (((src[4]) * 2 - (src[12]) + 2) >> 2) - (src[12]);
    t4 = (t0);
    t0 = (t1) - (t4);
    t1 = (t1) + (t4);
    t4 = (t0);
    t0 = (t2) - (t3);
    t2 = (t2) + (t3);
    t3 = (t0);
    dst[0] = flags[i] ? (t1) : 0;
    dst[4] = flags[i] ? (t2) : 0;
    dst[8] = flags[i] ? (t3) : 0;
    dst[12] = flags[i] ? (t4) : 0;
    src++;
    dst++;
}
}
