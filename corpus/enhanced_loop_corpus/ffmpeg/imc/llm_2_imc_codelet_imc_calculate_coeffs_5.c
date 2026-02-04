#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float workT2[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 32; i += 2) {
        workT2[i] = 0.;
        if (i + 1 < 32) {
            workT2[i + 1] = 0.;
        }
    }
}
