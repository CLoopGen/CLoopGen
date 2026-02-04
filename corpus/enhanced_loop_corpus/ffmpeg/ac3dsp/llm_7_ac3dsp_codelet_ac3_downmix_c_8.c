#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **samples;
extern float **matrix;
extern int in_ch;
extern int len;
extern int i;
extern int j;
extern float v0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        v0 = 0.F;
        for (j = 0; j < in_ch; j++) {
            v0 += samples[j][i] * matrix[0][j];
            matrix[0][j] += 1e-6F; // Introduce WAW and RAW dependency on matrix[0][j], creating loop-carried dependency
        }
        samples[0][i] = v0;
    }
}
