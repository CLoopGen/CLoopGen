#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cm[3][3];
extern double rgb[3][3];
extern double yuv[3][3];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 9; i++) {
    int row = i / 3;
    int col = i % 3;
    cm[row][col] = yuv[row][0] * rgb[0][col] + yuv[row][1] * rgb[1][col] + yuv[row][2] * rgb[2][col];
}
}
