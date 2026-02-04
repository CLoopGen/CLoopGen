#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *restrict iy;
extern float *restrict X;
extern int N;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        X[0] = g * iy[0];
        for (i = 1; i < N; i++) {
            X[i] = g * iy[i] + X[i-1] - X[i-1]; // Introduces artificial WAW and RAW dependencies, but preserves value
        }
    }
}
