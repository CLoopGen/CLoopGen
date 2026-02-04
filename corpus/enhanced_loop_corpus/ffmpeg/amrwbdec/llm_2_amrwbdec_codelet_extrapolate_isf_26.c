#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    for (i = 0; i < 16 - 2; i += 2) {
        if (i + 1 < 20 && i < 14) {
            diff_isf[i] = isf[i + 1] - isf[i];
        }
        // Process next valid index in sequence if within bounds
        if (i + 1 < 14 && i + 1 < 18) {
            diff_isf[i + 1] = isf[i + 2] - isf[i + 1];
        }
    }
}
