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
for (i = 0; i < N; i++) {
    for (int j = 0; j < 1; j++) {
        const float Xret = X[i];
        X[i] = (X[i] + Y[i]) * 0.70710678118654757;
        Y[i] = (Y[i] - Xret) * 0.70710678118654757;
    }
}
}
