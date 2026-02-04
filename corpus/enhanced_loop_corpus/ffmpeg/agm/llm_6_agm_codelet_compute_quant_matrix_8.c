#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_luma[64];
    int temp_chroma[64];
    double scaled_value = 16 - qscale * 32;
    int clamp_val = (1 > scaled_value) ? 1 : scaled_value;

    for (int i = 0; i < 64; i++) {
        temp_luma[i] = clamp_val;
        temp_chroma[i] = clamp_val;
    }

    for (int i = 0; i < 64; i++) {
        luma[i] = temp_luma[i];
        chroma[i] = temp_chroma[i];
    }
}
