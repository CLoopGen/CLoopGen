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
    float local_coeff = coeff;
    for (int i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            y[i]   = x[i]   + local_coeff * 0.850006103F;
            y[i+1] = x[i+1] + y[i] * 0.850006103F;
        } else {
            y[i] = x[i] + local_coeff * 0.850006103F;
        }
    }
    if (len > 0) {
        coeff = y[len - 1];
    }
}
