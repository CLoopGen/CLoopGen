#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *Y;
extern int N;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < N; i += 2) {
        const float Xret0 = X[i];
        X[i] = (X[i] + Y[i]) * 0.70710678118654757;
        Y[i] = (Y[i] - Xret0) * 0.70710678118654757;

        if (i + 1 < N) {
            const float Xret1 = X[i + 1];
            X[i + 1] = (X[i + 1] + Y[i + 1]) * 0.70710678118654757;
            Y[i + 1] = (Y[i + 1] - Xret1) * 0.70710678118654757;
        }
    }
}
