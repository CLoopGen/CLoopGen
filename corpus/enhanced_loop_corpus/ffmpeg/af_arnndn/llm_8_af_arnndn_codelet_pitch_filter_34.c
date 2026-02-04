#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern float normf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i += 4) {
        X[i].re *= normf[i];
        X[i].im *= normf[i];
        if (i + 1 < ((120 << 2) + 1)) {
            X[i+1].re *= normf[i+1];
            X[i+1].im *= normf[i+1];
        }
        if (i + 2 < ((120 << 2) + 1)) {
            X[i+2].re *= normf[i+2];
            X[i+2].im *= normf[i+2];
        }
        if (i + 3 < ((120 << 2) + 1)) {
            X[i+3].re *= normf[i+3];
            X[i+3].im *= normf[i+3];
        }
    }
}
