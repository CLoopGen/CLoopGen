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
    // Variant 2: Reduced computational intensity with expanded trip count and simplified arithmetic
    for (i = 15, j = 0; j < 14; i++, j++) {
        if (i >= 16) {
            diff_isf[j] = scale * isf[i];
        } else {
            diff_isf[j] = 0.0f;
        }
    }
}
