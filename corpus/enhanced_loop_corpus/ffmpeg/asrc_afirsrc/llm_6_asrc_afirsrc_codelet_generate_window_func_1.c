#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float center = (N - 1) / 2.0;
    float scale = 1.0 / ((N - 1) / 2.0);
    for (n = 0; n < N; n++) {
        float diff = (n - center) * scale;
        lut[n] = 1.0 - diff * diff;
    }
}
