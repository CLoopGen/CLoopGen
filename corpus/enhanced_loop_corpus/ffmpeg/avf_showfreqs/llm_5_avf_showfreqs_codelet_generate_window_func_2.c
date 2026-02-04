#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float inv_half_N = (N > 1) ? 2.0f / (N - 1) : 1.0f;
    float center = (N - 1) * 0.5f;
    for (n = 0; n < N; n++) {
        if (N <= 1) {
            lut[n] = 0.0f;
            continue;
        }
        float normalized = (n - center) * inv_half_N;
        lut[n] = 1.0f - normalized * normalized;
    }
}
