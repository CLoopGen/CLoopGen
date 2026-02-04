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
        float diff = (float)(n - center);
        float term1 = diff * inv_center;
        float term2 = term1 * term1;
        lut[n] = 1.0f - term2;
    }
}
