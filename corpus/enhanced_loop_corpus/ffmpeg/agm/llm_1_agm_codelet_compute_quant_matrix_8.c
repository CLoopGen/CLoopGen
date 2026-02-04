#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 8; k++) {
        for (int m = 0; m < 8; m++) {
            int i = k * 8 + m;
            luma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
            chroma[i] = ((1) > (16 - qscale * 32) ? (1) : (16 - qscale * 32));
        }
    }
}
