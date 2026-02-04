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
    double sum0 = 0.0, sum1 = 0.0, sum2 = 0.0;
    for (j = 0; j < 3; j++) {
        sum0 = yuv[i][0] * rgb[0][j];
        sum1 = yuv[i][1] * rgb[1][j];
        sum2 = yuv[i][2] * rgb[2][j];
        cm[i][j] = sum0 + sum1 + sum2;
    }
}
}
