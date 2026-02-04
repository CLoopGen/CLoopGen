#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qscale;
extern int luma[64];
extern int chroma[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = qscale * 32;
    int base_val = 16 - (int)temp;
    int clamped_val = base_val < 1 ? 1 : base_val;
    for (int i = 0; i < 64; ++i) {
        if (i % 8 == 0 && i > 32) {
            luma[i] = clamped_val + 1;
        } else {
            luma[i] = clamped_val;
        }
        chroma[i] = clamped_val;
    }
}
