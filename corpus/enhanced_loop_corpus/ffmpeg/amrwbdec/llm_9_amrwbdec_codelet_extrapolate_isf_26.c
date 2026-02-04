#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 1; i++) {
        float temp1 = isf[i + 1] - isf[i];
        float temp2 = (i + 2 < 20) ? isf[i + 2] - isf[i + 1] : 0.0f;
        diff_isf[i] = temp1 + temp2;
    }
}
