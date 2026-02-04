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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int idx = j * 8 + i;
            luma[idx] = ((1) > (unscaled_luma[(idx & 7) * 8 + (idx >> 3)] * f) ? (1) : (unscaled_luma[(idx & 7) * 8 + (idx >> 3)] * f));
            chroma[idx] = ((1) > (unscaled_chroma[(idx & 7) * 8 + (idx >> 3)] * f) ? (1) : (unscaled_chroma[(idx & 7) * 8 + (idx >> 3)] * f));
        }
    }
}
