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
    for (by = by0; by < by1; by += 2)
        for (bx = bx0; bx < bx1; bx += 2) {
            mv[0][by][bx] = mv[1][by][bx] = 0;
            if (by + 1 < by1) {
                mv[0][by+1][bx] = mv[1][by+1][bx] = 0;
            }
            if (bx + 1 < bx1) {
                mv[0][by][bx+1] = mv[1][by][bx+1] = 0;
            }
            if (by + 1 < by1 && bx + 1 < bx1) {
                mv[0][by+1][bx+1] = mv[1][by+1][bx+1] = 0;
            }
        }
}
