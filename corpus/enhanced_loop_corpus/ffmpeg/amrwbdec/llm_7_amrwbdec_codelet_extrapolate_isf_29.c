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
    float prev_isf = isf[16 - 1 - 1]; // isf[i-1] at first iteration
    for (i = 16 - 1, j = 0; i < 20 - 1; i++, j++) {
        float current_diff = scale * (isf[i] - prev_isf);
        diff_isf[j] = current_diff;
        prev_isf = isf[i]; // Introduce loop-carried dependency (WAW-like via prev_isf)
    }
}
