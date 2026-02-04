#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_n;
    if (N > 0) {
        for (outer_n = 0; outer_n < N; outer_n += 1) {
            n = outer_n;
            lut[n] = 1. - (n - (N - 1) / 2.) / ((N - 1) / 2.) * (n - (N - 1) / 2.) / ((N - 1) / 2.);
        }
    }
}
