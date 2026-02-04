#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern short ******all_mv;
extern short pmv[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int first_time = 1;
for (by = 0; by < 4; by++)
    for (bx = 0; bx < 4; bx++) {
        all_mv[bx][by][0][0][0][0] = pmv[0];
        all_mv[bx][by][0][0][0][1] = pmv[1];
        if (!first_time) continue;
        bx += 1; // Skip next bx on first iteration
        first_time = 0;
    }
}
