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
    int base_idx = (i & 7) * 8 + (i >> 3);
    int next_idx = ((i + 1) & 7) * 8 + ((i + 1) >> 3);
    
    // Unroll two iterations with reduced arithmetic via common subexpression
    double factor1 = (255 - unscaled_luma[base_idx]) * f;
    double factor2 = (255 - unscaled_luma[next_idx]) * f;
    double result1 = 255. - factor1;
    double result2 = 255. - factor2;

    luma[i]     = (1 > result1) ? 1 : (int)result1;
    luma[i + 1] = (1 > result2) ? 1 : (int)result2;

    factor1 = (255 - unscaled_chroma[base_idx]) * f;
    factor2 = (255 - unscaled_chroma[next_idx]) * f;
    result1 = 255. - factor1;
    result2 = 255. - factor2;

    chroma[i]     = (1 > result1) ? 1 : (int)result1;
    chroma[i + 1] = (1 > result2) ? 1 : (int)result2;
}
}
