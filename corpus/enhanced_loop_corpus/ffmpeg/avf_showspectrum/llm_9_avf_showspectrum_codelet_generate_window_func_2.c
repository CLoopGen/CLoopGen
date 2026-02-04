#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (N > 1000) ? 4 : 1;
    float center = (N - 1) / 2.0f;
    float inv_center_sq = 1.0f / (center * center);
    for (n = 0; n < N; n += step) {
        float diff = n - center;
        lut[n] = 1.0f - (diff * diff) * inv_center_sq;
    }
    for (int i = 0; i < N; i++) {
        if (i % step != 0) {
            float diff = i - center;
            lut[i] = 1.0f - (diff * diff) * inv_center_sq;
        }
    }
}
