#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (by = 0; by < 4; by += 2)
    for (bx = 0; bx < 4; bx += 2) {
        all_mv[bx][by][0][0][0][0] = pmv[0];
        all_mv[bx][by][0][0][0][1] = pmv[1];
        all_mv[bx+1][by][0][0][0][0] = pmv[0];
        all_mv[bx+1][by][0][0][0][1] = pmv[1];
        all_mv[bx][by+1][0][0][0][0] = pmv[0];
        all_mv[bx][by+1][0][0][0][1] = pmv[1];
        all_mv[bx+1][by+1][0][0][0][0] = pmv[0];
        all_mv[bx+1][by+1][0][0][0][1] = pmv[1];
    }
}
