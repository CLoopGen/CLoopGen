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
for (x = 0; x < 16; x += 2) {
    int dot = dots[x];
    int bits = 0;
    if (dot < c3_point) bits |= 1;
    if (dot < c0_point) bits |= 2;
    if (dot < half_point) bits |= 4;
    mask >>= 1;
    mask |= ((indexMap[bits] & 1) << 31);
    
    if (x + 1 < 16) {
        dot = dots[x+1];
        bits = (dot < half_point) + 2*(dot < c0_point) + 4*(dot < half_point && dot >= c3_point);
        mask >>= 1;
        mask |= ((indexMap[bits] & 1) << 31);
    }
}
}
