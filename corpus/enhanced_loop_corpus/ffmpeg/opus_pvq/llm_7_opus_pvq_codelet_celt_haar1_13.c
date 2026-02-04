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
        float prev_result = 0.0f;
        for (j = 0; j < N0; j++) {
            int idx0 = stride * (2 * j + 0) + i;
            int idx1 = stride * (2 * j + 1) + i;
            float x0 = X[idx0];
            float x1 = X[idx1];
            float sum = (x0 + x1) * 0.70710678118654757;
            float diff = (x0 - x1) * 0.70710678118654757;
            X[idx0] = sum + prev_result;
            X[idx1] = diff;
            prev_result = sum * 0.5f;
        }
    }
}
