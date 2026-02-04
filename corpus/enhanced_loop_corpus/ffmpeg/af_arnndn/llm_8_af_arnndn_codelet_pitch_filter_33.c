#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern AVComplexFloat *X;
extern  AVComplexFloat *P;
extern float rf[481];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i += 2) {
        if (i + 1 < ((120 << 2) + 1)) {
            X[i].re += rf[i] * P[i].re;
            X[i].im += rf[i] * P[i].im;
            X[i+1].re += rf[i+1] * P[i+1].re;
            X[i+1].im += rf[i+1] * P[i+1].im;
        } else {
            X[i].re += rf[i] * P[i].re;
            X[i].im += rf[i] * P[i].im;
        }
    }
}
