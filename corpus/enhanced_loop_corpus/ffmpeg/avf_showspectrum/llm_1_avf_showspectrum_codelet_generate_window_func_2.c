#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block = 0; block < N; block += 16) {
    for (n = block; n < N && n < block + 16; n++)
        lut[n] = 1. - (n - (N - 1) / 2.) / ((N - 1) / 2.) * (n - (N - 1) / 2.) / ((N - 1) / 2.);
}
}
