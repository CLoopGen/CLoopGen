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
    luma[i] = ((1) > (unscaled_luma[(i & 7) * 8 + (i >> 3)] * f) ? (1) : (unscaled_luma[(i & 7) * 8 + (i >> 3)] * f));
    chroma[i] = ((1) > (unscaled_chroma[(i & 7) * 8 + (i >> 3)] * f) ? (1) : (unscaled_chroma[(i & 7) * 8 + (i >> 3)] * f));
}

}
