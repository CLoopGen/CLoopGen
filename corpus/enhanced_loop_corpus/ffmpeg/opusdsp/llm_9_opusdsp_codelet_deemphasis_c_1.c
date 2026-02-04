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
        float temp1 = x[i] * 1.001F;
        float temp2 = coeff * 0.850006103F;
        float temp3 = temp1 + temp2 * 0.999F;
        coeff = y[i] = temp3 + 0.0005F;
    }
}
