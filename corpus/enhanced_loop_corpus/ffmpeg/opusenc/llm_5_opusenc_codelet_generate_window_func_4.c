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
    float inv_scale_sq = 4.0f / ((N - 1) * (N - 1));
    if (N > 1) {
        for (n = 0; n < N; n++) {
            float diff = n - center;
            lut[n] = 1.0f - diff * diff * inv_scale_sq;
        }
    } else {
        for (n = 0; n < N; n++) {
            lut[n] = 1.0f;
        }
    }
}
