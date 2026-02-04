#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int index = 0; index < 16; index++) {
    bx = index % 4;
    by = index / 4;
    all_mv[bx][by][0][0][0][0] = pmv[0];
    all_mv[bx][by][0][0][0][1] = pmv[1];
}
}
