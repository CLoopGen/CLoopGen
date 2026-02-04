#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *lut;
extern int N;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Traverse the array from the last element to the first
    int i;
    for (i = N - 1; i >= 0; i--) {
        lut[i] = 1. - (i - (N - 1) / 2.) / ((N - 1) / 2.) * (i - (N - 1) / 2.) / ((N - 1) / 2.);
    }
}
