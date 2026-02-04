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
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            for (int m = 0; m < 4; m++) {
                for (int n = 0; n < 4; n++) {
                    int i = j * 16 + k * 8 + m * 4 + n;
                    if (i < 64) {
                        luma[i] = ((1) > (255. - (255 - unscaled_luma[(i & 7) * 8 + (i >> 3)]) * f) ? (1) : (255. - (255 - unscaled_luma[(i & 7) * 8 + (i >> 3)]) * f));
                        chroma[i] = ((1) > (255. - (255 - unscaled_chroma[(i & 7) * 8 + (i >> 3)]) * f) ? (1) : (255. - (255 - unscaled_chroma[(i & 7) * 8 + (i >> 3)]) * f));
                    }
                }
            }
        }
    }
}
