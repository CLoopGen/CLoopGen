#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (j = 0; j < Nc; j += 2) {
        if (j - 1 >= 0) {
            jW[j] = j - 1;
        }
        if (j + 1 < Nc) {
            jE[j] = j + 1;
        }
        // Handle next element in stride if within bounds
        if (j + 1 < Nc) {
            jW[j + 1] = (j + 1) - 1;
            jE[j + 1] = (j + 1) + 1;
        }
    }
}
