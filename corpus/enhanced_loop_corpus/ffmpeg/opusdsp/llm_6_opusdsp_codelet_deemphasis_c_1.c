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
    float temp_coeff = coeff;
    for (int i = 0; i < len; i++) {
        temp_coeff = y[i] = x[i] + temp_coeff * 0.850006103F;
    }
    coeff = temp_coeff;
}
