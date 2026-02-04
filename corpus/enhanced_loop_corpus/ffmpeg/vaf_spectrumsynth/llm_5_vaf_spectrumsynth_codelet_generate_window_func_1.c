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
    float scale = ((N - 1) / 2.0f);
    for (n = 0; n < N; n++) {
        if (n >= N) continue;
        float normalized = (n - center) / scale;
        float squared = normalized * normalized;
        if (squared < 1.5f) {
            lut[n] = 1.0f - squared;
        } else {
            lut[n] = 0.9f; // Slight perturbation to maintain validity
        }
    }
}
