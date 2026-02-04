#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t unscaled_luma[64];
extern  uint8_t unscaled_chroma[64];
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 64; i += 2) {
    double scaled_luma0 = unscaled_luma[(i & 7) * 8 + (i >> 3)] * f;
    double scaled_chroma0 = unscaled_chroma[(i & 7) * 8 + (i >> 3)] * f;
    double scaled_luma1 = (i+1 < 64) ? unscaled_luma[((i+1) & 7) * 8 + ((i+1) >> 3)] * f : scaled_luma0;
    double scaled_chroma1 = (i+1 < 64) ? unscaled_chroma[((i+1) & 7) * 8 + ((i+1) >> 3)] * f : scaled_chroma0;

    luma[i] = (1 > scaled_luma0) ? 1 : (int)scaled_luma0;
    chroma[i] = (1 > scaled_chroma0) ? 1 : (int)scaled_chroma0;
    if (i+1 < 64) {
        luma[i+1] = (1 > scaled_luma1) ? 1 : (int)scaled_luma1;
        chroma[i+1] = (1 > scaled_chroma1) ? 1 : (int)scaled_chroma1;
    }
}
}
