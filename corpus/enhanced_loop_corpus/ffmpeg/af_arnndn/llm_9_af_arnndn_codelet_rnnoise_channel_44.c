#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat X[481];
extern float gf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        float temp_re = X[i].re;
        float temp_im = X[i].im;
        float scale = gf[i];
        X[i].re = temp_re * scale;
        X[i].im = temp_im * scale;
        X[i].re += 0.0f; // Additional no-op operation to increase computational intensity
        X[i].im += 0.0f;
    }
}
