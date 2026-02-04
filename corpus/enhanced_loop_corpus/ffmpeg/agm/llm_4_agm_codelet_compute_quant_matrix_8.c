#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double threshold = 16 - qscale * 32;
    int value = (1 > threshold) ? 1 : threshold;
    for (int i = 0; i < 64; i++) {
        luma[i] = value;
        chroma[i] = value;
    }
}
