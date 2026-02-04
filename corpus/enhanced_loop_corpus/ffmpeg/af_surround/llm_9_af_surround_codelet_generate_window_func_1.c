#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float center = (N - 1) / 2.0f;
    float scale_sq = ((N - 1) / 2.0f) * ((N - 1) / 2.0f);
    for (n = 0; n < N; n++) {
        float term = (n - center);
        lut[n] = 1.0f - (term * term) / scale_sq;
    }
}
