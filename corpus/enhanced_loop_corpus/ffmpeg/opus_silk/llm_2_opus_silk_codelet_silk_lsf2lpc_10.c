#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float lpcf[16];
extern int order;
extern int i;
extern int16_t lpc[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Processes elements in a strided manner: i and i+1 with step 2
    for (i = 0; i < order; i += 2) {
        if (i < order) {
            lpcf[i] = lpc[i] / 4096.F;
        }
        if (i + 1 < order) {
            lpcf[i + 1] = lpc[i + 1] / 4096.F;
        }
    }
}
