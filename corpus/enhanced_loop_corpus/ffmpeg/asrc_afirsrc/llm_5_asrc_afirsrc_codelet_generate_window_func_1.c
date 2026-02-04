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
        float center = (N - 1) / 2.;
        float diff = (n - center) / center;
        if (n >= center) {
            lut[n] = 1.0f - diff * diff;
        } else {
            lut[n] = 1.0f;
        }
    }
}
