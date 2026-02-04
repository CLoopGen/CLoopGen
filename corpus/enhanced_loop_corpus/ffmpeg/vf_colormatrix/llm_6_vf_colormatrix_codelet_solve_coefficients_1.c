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
    double temp[3][3];
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++) {
            temp[i][j] = yuv[i][0] * rgb[0][j];
            temp[i][j] += yuv[i][1] * rgb[1][j];
            temp[i][j] += yuv[i][2] * rgb[2][j];
        }
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cm[i][j] = temp[i][j];
}
