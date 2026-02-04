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
// Change to strided memory access with step of 8, unrolling to maintain 64 iterations
for (int stride = 0; stride < 8; stride++) {
    for (int base = 0; base < 8; base++) {
        int i = base * 8 + stride; // Now accessing in column-major (strided) order
        luma[i] = (1 > (255. - (255 - unscaled_luma[i]) * f)) ? 1 : (int)(255. - (255 - unscaled_luma[i]) * f);
        chroma[i] = (1 > (255. - (255 - unscaled_chroma[i]) * f)) ? 1 : (int)(255. - (255 - unscaled_chroma[i]) * f);
    }
}
}
