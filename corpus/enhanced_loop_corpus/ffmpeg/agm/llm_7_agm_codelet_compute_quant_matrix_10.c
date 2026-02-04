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
    int temp_luma, temp_chroma;
    for (int i = 0; i < 64; i++) {
        int idx = (i & 7) * 8 + (i >> 3);
        double scaled_luma = 255. - (255 - unscaled_luma[idx]) * f;
        double scaled_chroma = 255. - (255 - unscaled_chroma[idx]) * f;
        temp_luma = (1 > scaled_luma) ? 1 : (int)scaled_luma;
        temp_chroma = (1 > scaled_chroma) ? 1 : (int)scaled_chroma;
        luma[i] = temp_luma;
        chroma[i] = temp_chroma;
    }
}
