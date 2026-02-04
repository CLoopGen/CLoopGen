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
for (int i = 0; i < 64; i++) {
    int index = (i & 7) * 8 + (i >> 3);
    double luma_val = (255 - unscaled_luma[index]) * f;
    double chroma_val = (255 - unscaled_chroma[index]) * f;

    if (luma_val > 254) {
        luma[i] = 1;
    } else {
        luma[i] = 255 - luma_val;
    }

    if (chroma_val > 254) {
        chroma[i] = 1;
    } else {
        chroma[i] = 255 - chroma_val;
    }
}
}
