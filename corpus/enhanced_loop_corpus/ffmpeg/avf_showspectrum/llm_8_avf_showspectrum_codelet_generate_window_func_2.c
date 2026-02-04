#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n += 2) {
        float center = (N - 1) / 2.0f;
        float diff = (n - center) / center;
        lut[n] = 1.0f - diff * diff;
        if (n + 1 < N) {
            float diff_next = (n + 1 - center) / center;
            lut[n + 1] = 1.0f - diff_next * diff_next;
        }
    }
}
