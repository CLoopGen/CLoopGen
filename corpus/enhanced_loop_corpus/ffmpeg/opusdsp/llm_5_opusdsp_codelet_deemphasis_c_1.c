#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float *x;
extern float coeff;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            coeff = x[i] + coeff * 0.850006103F;
        } else {
            coeff = x[i] + coeff * 0.850006103F + 0.001F;
        }
        y[i] = coeff;
    }
}
