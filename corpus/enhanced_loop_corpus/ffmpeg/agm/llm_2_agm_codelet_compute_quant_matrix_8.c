#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 64; i += 2) {
    luma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
    chroma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
    if (i + 1 < 64) {
        luma[i + 1] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
        chroma[i + 1] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
    }
}
}
