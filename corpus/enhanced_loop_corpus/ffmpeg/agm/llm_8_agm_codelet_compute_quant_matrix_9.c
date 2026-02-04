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
for (int i = 0; i < 32; i++) {
    int idx_luma = (i & 7) * 8 + (i >> 3);
    int idx_chroma = idx_luma;
    double temp_luma = unscaled_luma[idx_luma] * f;
    double temp_chroma = unscaled_chroma[idx_chroma] * f;
    luma[i] = (1 > temp_luma) ? 1 : (int)temp_luma;
    chroma[i] = (1 > temp_chroma) ? 1 : (int)temp_chroma;
    luma[63 - i] = (1 > temp_luma) ? 1 : (int)temp_luma;
    chroma[63 - i] = (1 > temp_chroma) ? 1 : (int)temp_chroma;
}
}
