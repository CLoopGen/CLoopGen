#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern  float *y;
extern int N;
extern float xy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    xy = 0.0f;
    for (int i = 0; i < N; ++i) {
        float prod = x[i] * y[i];
        if (!(prod < 1e-6f && prod > -1e-6f)) {
            xy += prod;
        }
    }
}
