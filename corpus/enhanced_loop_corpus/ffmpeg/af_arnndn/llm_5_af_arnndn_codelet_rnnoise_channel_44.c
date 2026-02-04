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
        float g_val = gf[i];
        if (g_val > 1e-6f) {
            X[i].re *= g_val;
            X[i].im *= g_val;
        } else {
            X[i].re = 0.0f;
            X[i].im = 0.0f;
        }
    }
}
