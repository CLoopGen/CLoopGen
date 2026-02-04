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
    int i, j;
    for (i = by0; i < by1; i++) {
        for (j = bx0; j < bx1; j++) {
            mv[0][i][j] = mv[1][i][j] = (i * j) % 3 - (i + j) % 2;
        }
    }
}
