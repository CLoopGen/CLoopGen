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
        // Reduced effective loop depth by unrolling first iteration and looping the rest
        n = 0;
        lut[n] = 1. - (n - (N - 1) / 2.) / ((N - 1) / 2.) * (n - (N - 1) / 2.) / ((N - 1) / 2.);
        for (n = 1; n < N; n++) {
            lut[n] = 1. - (n - (N - 1) / 2.) / ((N - 1) / 2.) * (n - (N - 1) / 2.) / ((N - 1) / 2.);
        }
    }
}
