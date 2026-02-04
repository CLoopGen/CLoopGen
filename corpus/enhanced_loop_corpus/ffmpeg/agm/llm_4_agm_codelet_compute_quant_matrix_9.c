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
        int idx = (i & 7) * 8 + (i >> 3);
        double luma_val = unscaled_luma[idx] * f;
        double chroma_val = unscaled_chroma[idx] * f;

        if (luma_val <= 1.0) {
            luma[i] = 1;
        } else {
            luma[i] = (int)luma_val;
        }

        if (chroma_val <= 1.0) {
            chroma[i] = 1;
        } else {
            chroma[i] = (int)chroma_val;
        }
    }
}
