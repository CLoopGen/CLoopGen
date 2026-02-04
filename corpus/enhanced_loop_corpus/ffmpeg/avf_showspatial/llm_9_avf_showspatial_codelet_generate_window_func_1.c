#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    float center = (N - 1) / 2.0f;
    float inv_center_sq = 1.0f / (center * center);
    for (i = 0; i < N; i++) {
        float diff = i - center;
        lut[i] = 1.0f - (diff * diff) * inv_center_sq;
    }
}
