#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern float scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 16 - 1, j = 0; i < 20 - 1; i++, j++) {
        float temp = isf[i] - isf[i - 1];
        diff_isf[j] = scale * temp;
    }
}
