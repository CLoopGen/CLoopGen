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
    for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 8; k++) {
            int i = j * 8 + k;
            luma[i] = ((1) > (255. - (255 - unscaled_luma[k * 8 + j]) * f) ? (1) : (255. - (255 - unscaled_luma[k * 8 + j]) * f));
            chroma[i] = ((1) > (255. - (255 - unscaled_chroma[k * 8 + j]) * f) ? (1) : (255. - (255 - unscaled_chroma[k * 8 + j]) * f));
        }
    }
}
