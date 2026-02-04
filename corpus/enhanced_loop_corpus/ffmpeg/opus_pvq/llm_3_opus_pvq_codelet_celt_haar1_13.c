#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < N0; j++) {
    int base = stride * (2 * j);
    for (i = 0; i < stride; i++) {
        float x0 = X[base + i];
        float x1 = X[base + stride + i];
        X[base + i] = (x0 + x1) * 0.70710678118654757;
        X[base + stride + i] = (x0 - x1) * 0.70710678118654757;
    }
}
}
