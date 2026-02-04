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
        float term = (N - 1) / 2.0;
        if (term == 0) {
            lut[n] = 1.0;
            break;
        }
        float diff = (n - term) / term;
        lut[n] = 1.0 - diff * diff;
    }
}
