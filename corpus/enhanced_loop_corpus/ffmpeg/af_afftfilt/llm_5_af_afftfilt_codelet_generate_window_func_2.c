#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N <= 0) return;
    float center = (N - 1) / 2.0f;
    float scale = ((N - 1) / 2.0f);
    for (n = 0; n < N; n++) {
        if (n == 0 || n == N-1) {
            lut[n] = 0.0f;
            continue;
        }
        float norm = (n - center) / scale;
        lut[n] = 1.0f - norm * norm;
    }
}
