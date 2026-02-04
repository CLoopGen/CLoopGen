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
    float inv_center = 1.0f / center;
    for (n = 0; n < N; n++) {
        float diff = (n - center) * inv_center;
        lut[n] = 1.0f - diff * diff;
    }
}
