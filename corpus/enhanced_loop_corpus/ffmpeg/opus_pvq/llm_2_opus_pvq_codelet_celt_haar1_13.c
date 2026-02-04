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
for (i = 0; i < stride; i++) {
    for (j = 0; j < N0; j++) {
        int idx0 = stride * (2 * j + 0) + i;
        int idx1 = stride * (2 * j + 1) + i;
        float x0 = X[idx0];
        float x1 = X[idx1];
        X[idx0] = (x0 + x1) * 0.70710678118654757;
        X[idx1] = (x0 - x1) * 0.70710678118654757;
    }
}
}
