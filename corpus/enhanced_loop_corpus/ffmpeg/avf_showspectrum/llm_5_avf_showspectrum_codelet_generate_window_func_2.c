#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n++) {
        float normalized = (n - (N - 1) / 2.) / ((N - 1) / 2.);
        if (normalized >= -1.0f && normalized <= 1.0f) {
            lut[n] = 1.0f - normalized * normalized;
        } else {
            lut[n] = 0.0f;
        }
    }
}
