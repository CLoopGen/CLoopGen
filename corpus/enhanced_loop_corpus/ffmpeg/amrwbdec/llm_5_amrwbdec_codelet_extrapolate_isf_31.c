#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15, j = 0; i < 19 && j < 14; i++, j++) {
        float increment = (j < 10) ? diff_isf[j] * (1.F / (1 << 15)) : 0.0F;
        isf[i] = isf[i - 1] + increment;
    }
}
