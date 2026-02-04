#include <stdio.h>

#include <inttypes.h>

extern int bx;
extern int by;
extern int mv[2][4][4];
extern int bx0;
extern int bx1;
extern int by0;
extern int by1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (by = by0; by < by1; by++) {
        if (by % 2 == 1) {
            continue;
        }
        for (bx = bx0; bx < bx1; bx++) {
            mv[0][by][bx] = mv[1][by][bx] = 0;
        }
    }
}
