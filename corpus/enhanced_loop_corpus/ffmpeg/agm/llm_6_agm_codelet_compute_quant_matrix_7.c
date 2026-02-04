#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_luma;
    int temp_chroma;
    for (int i = 0; i < 64; i++) {
        temp_luma = (1 > (16 * f)) ? 1 : (16 * f);
        temp_chroma = (1 > (16 * f)) ? 1 : (16 * f);
        luma[i] = temp_luma;
        chroma[i] = temp_chroma;
    }
}
