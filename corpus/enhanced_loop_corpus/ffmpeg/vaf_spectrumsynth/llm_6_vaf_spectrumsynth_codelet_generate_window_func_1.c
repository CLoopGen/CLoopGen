#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float base = (N - 1) / 2.0;
    float inv_base_sq = 1.0 / (base * base);
    for (n = 0; n < N; n++) {
        float diff = n - base;
        lut[n] = 1.0 - (diff * diff) * inv_base_sq;
    }
}
