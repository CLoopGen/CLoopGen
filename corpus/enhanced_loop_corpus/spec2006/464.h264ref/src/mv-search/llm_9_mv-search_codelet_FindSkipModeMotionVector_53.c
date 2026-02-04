#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total = 8; // Increased trip count with more operations
for (int i = 0; i < total; i++) {
    int by_inner = (i >> 2) & 3;
    int bx_inner = i & 3;
    short temp0 = pmv[0] + (short)(bx_inner ^ by_inner);
    short temp1 = pmv[1] - (short)(bx_inner & by_inner);
    all_mv[bx_inner][by_inner][0][0][0][0] = temp0;
    all_mv[bx_inner][by_inner][0][0][0][1] = temp1;
}
}
