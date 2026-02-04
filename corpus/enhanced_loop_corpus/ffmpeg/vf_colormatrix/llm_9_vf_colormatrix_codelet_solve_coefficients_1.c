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
for (i = 0; i < 2; i += 1) {
    for (j = 0; j < 2; j += 1) {
        double temp = 0.0;
        for (int k = 0; k < 3; k++) {
            temp += yuv[i][k] * rgb[k][j];
        }
        cm[i][j] = temp;
    }
}
cm[2][2] = yuv[2][0] * rgb[0][2] + yuv[2][1] * rgb[1][2] + yuv[2][2] * rgb[2][2];
}
