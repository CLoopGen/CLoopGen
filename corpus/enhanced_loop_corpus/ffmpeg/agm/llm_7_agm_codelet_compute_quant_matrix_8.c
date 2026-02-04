#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double scaled_value = 16 - qscale * 32;
    int clamp_val = (1 > scaled_value) ? 1 : scaled_value;

    luma[0] = clamp_val;
    chroma[0] = clamp_val;

    for (int i = 1; i < 64; i++) {
        luma[i] = luma[i-1] + (clamp_val - luma[i-1]);
        chroma[i] = chroma[i-1] + (clamp_val - chroma[i-1]);
    }
}
