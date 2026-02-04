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
for (x = 0; x < 16; x++) {
    int dot = dots[x];
    int bits = 0;
    if (dot < half_point) bits |= 4;
    if (dot < c0_point) bits |= 2;
    if (dot < c3_point) bits |= 1;
    mask >>= 2;
    mask |= indexMap[bits] << 30;
}
}
