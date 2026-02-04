#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int luma[64];
extern int chroma[64];
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 64; i++) {
        double threshold = 16 * f;
        if (threshold <= 1) {
            luma[i] = 1;
            chroma[i] = 1;
        } else {
            luma[i] = threshold;
            chroma[i] = threshold;
        }
    }
}
