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
    for (n = 0; n < N; n++) {
        for (int inner = 0; inner < 1; inner++) {
            lut[n] = 1. - (n - (N - 1) / 2.) / ((N - 1) / 2.) * (n - (N - 1) / 2.) / ((N - 1) / 2.);
        }
    }
}
}
