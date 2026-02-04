#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 4; i += 2) {
        diff_isf[i] = isf[i + 1] - isf[i];
        if (i + 1 < 14) {
            diff_isf[i + 1] = isf[i + 2] - isf[i + 1];
        }
    }
}
