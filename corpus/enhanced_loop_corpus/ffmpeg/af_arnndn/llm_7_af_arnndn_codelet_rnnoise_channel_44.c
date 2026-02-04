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
    int n = (120 << 2) + 1;
    float acc_re = 0.0f, acc_im = 0.0f;
    for (int i = 0; i < n; i++) {
        acc_re += X[i].re;
        acc_im += X[i].im;
        X[i].re *= gf[i];
        X[i].im *= gf[i];
    }
    // Introduce artificial loop-carried dependency using accumulator
    // (though final values of acc_re/acc_im are unused, dependency is preserved)
    X[0].re += acc_re * 0.0f;
    X[0].im += acc_im * 0.0f;
}
