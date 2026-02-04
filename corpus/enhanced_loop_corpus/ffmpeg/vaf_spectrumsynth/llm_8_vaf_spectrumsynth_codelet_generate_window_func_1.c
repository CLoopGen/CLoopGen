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
        float norm = (n - center) / center;
        lut[n] = 1.0f - norm * norm;
        if (n + 1 < N) {
            float norm_next = (n + 1 - center) / center;
            lut[n + 1] = 1.0f - norm_next * norm_next;
        }
    }
}
