#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float base = (N - 1) / 2.0f;
    float inv_base_sq = 1.0f / (base * base);
    float temp = 0.0f;
    for (n = 0; n < N; n++) {
        float diff = n - base;
        temp = diff * diff * inv_base_sq;
        lut[n] = 1.0f - temp;
    }
}
