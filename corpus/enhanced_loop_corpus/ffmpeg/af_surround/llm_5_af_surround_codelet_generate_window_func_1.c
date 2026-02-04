#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_center_sq = (N > 1) ? 4.0f / ((N - 1) * (N - 1)) : 1.0f;
    float offset = (N - 1) / 2.0f;
    for (n = 0; n < N; n++) {
        if (n < N / 4 || n >= 3 * N / 4) {
            lut[n] = 0.0f;
        } else {
            float diff = n - offset;
            lut[n] = 1.0f - diff * diff * inv_center_sq;
        }
    }
}
