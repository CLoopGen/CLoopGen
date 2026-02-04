#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (by = 0; by < 4; by++) {
    all_mv[0][by][0][0][0][0] = pmv[0];
    all_mv[0][by][0][0][0][1] = pmv[1];
    all_mv[1][by][0][0][0][0] = pmv[0];
    all_mv[1][by][0][0][0][1] = pmv[1];
    all_mv[2][by][0][0][0][0] = pmv[0];
    all_mv[2][by][0][0][0][1] = pmv[1];
    all_mv[3][by][0][0][0][0] = pmv[0];
    all_mv[3][by][0][0][0][1] = pmv[1];
}
}
