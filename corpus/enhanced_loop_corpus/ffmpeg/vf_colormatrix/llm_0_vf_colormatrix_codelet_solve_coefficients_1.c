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
for (i = 0; i < 3; i++) {
    cm[i][0] = yuv[i][0] * rgb[0][0] + yuv[i][1] * rgb[1][0] + yuv[i][2] * rgb[2][0];
    cm[i][1] = yuv[i][0] * rgb[0][1] + yuv[i][1] * rgb[1][1] + yuv[i][2] * rgb[2][1];
    cm[i][2] = yuv[i][0] * rgb[0][2] + yuv[i][1] * rgb[1][2] + yuv[i][2] * rgb[2][2];
}
}
