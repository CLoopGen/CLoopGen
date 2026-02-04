#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t mask;
extern int dots[16];
extern int x;
extern int c0_point;
extern int half_point;
extern int c3_point;
extern  int indexMap[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 8; x++) {
    int dot1 = dots[2*x];
    int dot2 = dots[2*x + 1];
    int bits1 = (dot1 < half_point ? 4 : 0) | (dot1 < c0_point ? 2 : 0) | (dot1 < c3_point ? 1 : 0);
    int bits2 = (dot2 < half_point ? 4 : 0) | (dot2 < c0_point ? 2 : 0) | (dot2 < c3_point ? 1 : 0);
    mask >>= 4;
    mask |= indexMap[bits1] << 2;
    mask |= indexMap[bits2];
}
}
