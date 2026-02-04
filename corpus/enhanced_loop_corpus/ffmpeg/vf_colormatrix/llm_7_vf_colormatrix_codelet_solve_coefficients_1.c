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
    for (j = 0; j < 3; j++)
        for (i = 0; i < 3; i++) {
            cm[i][j] = 0.0;
            for (int k = 0; k < 3; k++)
                cm[i][j] += yuv[i][k] * rgb[k][j];
        }
}
