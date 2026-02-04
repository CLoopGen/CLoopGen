#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order memory access
    for (i = 16 - 3; i >= 0; i--) {
        diff_isf[i] = isf[i + 1] - isf[i];
    }
}
