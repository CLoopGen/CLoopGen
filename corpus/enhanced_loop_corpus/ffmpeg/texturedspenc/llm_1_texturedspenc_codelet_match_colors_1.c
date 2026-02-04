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
for (int level1 = 0; level1 < 2; level1++) {
    for (int level2 = 0; level2 < 2; level2++) {
        for (int level3 = 0; level3 < 4; level3++) {
            x = (level1 * 8) + (level2 * 4) + level3;
            int dot = dots[x];
            int bits = (dot < half_point ? 4 : 0) | (dot < c0_point ? 2 : 0) | (dot < c3_point ? 1 : 0);
            mask >>= 2;
            mask |= indexMap[bits];
        }
    }
}
}
