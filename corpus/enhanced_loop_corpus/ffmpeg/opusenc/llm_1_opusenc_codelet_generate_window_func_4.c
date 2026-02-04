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
        int i = 0;
        for (; i < N / 2; i++) {
            lut[i] = 1. - (i - (N - 1) / 2.) / ((N - 1) / 2.) * (i - (N - 1) / 2.) / ((N - 1) / 2.);
        }
        for (; i < N; i++) {
            lut[i] = 1. - (i - (N - 1) / 2.) / ((N - 1) / 2.) * (i - (N - 1) / 2.) / ((N - 1) / 2.);
        }
    }
}
