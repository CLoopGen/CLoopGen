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
    int idx = (i & 7) * 8 + (i >> 3);
    double luma_val = 255. - (255 - unscaled_luma[idx]) * f;
    double chroma_val = 255. - (255 - unscaled_chroma[idx]) * f;
    luma[i * 2] = luma[i * 2 + 1] = (1 > luma_val) ? 1 : (int)luma_val;
    chroma[i * 2] = chroma[i * 2 + 1] = (1 > chroma_val) ? 1 : (int)chroma_val;
}
}
