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
    int temp_luma[64];
    int temp_chroma[64];
    for (int i = 0; i < 64; i++) {
        temp_luma[i] = unscaled_luma[(i & 7) * 8 + (i >> 3)] * f;
        temp_chroma[i] = unscaled_chroma[(i & 7) * 8 + (i >> 3)] * f;
    }
    for (int i = 0; i < 64; i++) {
        luma[i] = (1 > temp_luma[i]) ? 1 : temp_luma[i];
        chroma[i] = (1 > temp_chroma[i]) ? 1 : temp_chroma[i];
    }
}
