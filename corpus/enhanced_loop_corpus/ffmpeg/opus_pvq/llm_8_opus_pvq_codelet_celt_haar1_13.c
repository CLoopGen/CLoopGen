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
    for (j = 0; j < N0; j += 2) {
        if (j + 1 < N0) {
            float x0 = X[stride * (2 * j + 0) + i];
            float x1 = X[stride * (2 * j + 1) + i];
            float y0 = X[stride * (2 * (j+1) + 0) + i];
            float y1 = X[stride * (2 * (j+1) + 1) + i];
            X[stride * (2 * j + 0) + i] = (x0 + x1) * 0.70710678118654757;
            X[stride * (2 * j + 1) + i] = (x0 - x1) * 0.70710678118654757;
            X[stride * (2 * (j+1) + 0) + i] = (y0 + y1) * 0.70710678118654757;
            X[stride * (2 * (j+1) + 1) + i] = (y0 - y1) * 0.70710678118654757;
        }
    }
}
}
