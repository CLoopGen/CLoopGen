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
for (i = 0; i < stride; i += 2) {
    if (i + 1 < stride) {
        for (j = 0; j < N0; j++) {
            float x0 = X[stride * (2 * j + 0) + i];
            float x1 = X[stride * (2 * j + 1) + i];
            float x2 = X[stride * (2 * j + 0) + i + 1];
            float x3 = X[stride * (2 * j + 1) + i + 1];
            X[stride * (2 * j + 0) + i] = (x0 + x1) * 0.70710678118654757;
            X[stride * (2 * j + 1) + i] = (x0 - x1) * 0.70710678118654757;
            X[stride * (2 * j + 0) + i + 1] = (x2 + x3) * 0.70710678118654757;
            X[stride * (2 * j + 1) + i + 1] = (x2 - x3) * 0.70710678118654757;
        }
    }
}
}
