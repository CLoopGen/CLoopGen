#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (N > 0) {
        int mid = (N - 1) / 2;
        float scale = 1.0f / ((N - 1) / 2.);
        for (int n = 0; n < N; n++) {
            float diff = (n - mid) * scale;
            lut[n] = 1.0f - diff * diff;
        }
    }
}
