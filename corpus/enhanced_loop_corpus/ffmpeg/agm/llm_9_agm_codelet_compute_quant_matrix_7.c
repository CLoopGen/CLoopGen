#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 64; i += 4) {
    double scaled_f = 16.0 * f;
    int val = (1 > scaled_f) ? 1 : (int)scaled_f;
    luma[i] = val;
    chroma[i] = val;
    if (i+1 < 64) {
        luma[i+1] = val;
        chroma[i+1] = val;
    }
    if (i+2 < 64) {
        luma[i+2] = val;
        chroma[i+2] = val;
    }
    if (i+3 < 64) {
        luma[i+3] = val;
        chroma[i+3] = val;
    }
}
}
