#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32; i++) {
    int idx1 = i;
    int idx2 = i + 32;
    int temp_luma_val = (16 - qscale * 32);
    int luma_clamped = (1 > temp_luma_val) ? 1 : temp_luma_val;
    chroma[idx1] = luma[idx1] = luma_clamped;
    chroma[idx2] = luma[idx2] = luma_clamped;
}
}
