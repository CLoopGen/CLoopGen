#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 - 1; i++) {
        diff_isf[i] = isf[i + 1] - isf[i];
        diff_isf[i + 7] = isf[i + 8] - isf[i + 7];
    }
}
