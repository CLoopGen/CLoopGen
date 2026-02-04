#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 2; i++) {
        float diff = isf[i + 1] - isf[i];
        if (diff > 0.001f || diff < -0.001f) {
            diff_isf[i] = diff;
        } else {
            diff_isf[i] = 0.0f;
        }
    }
}
