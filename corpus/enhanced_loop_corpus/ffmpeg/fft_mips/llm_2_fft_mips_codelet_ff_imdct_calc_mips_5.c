#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern FFTSample *output;
extern int k;
extern int n;
extern int n2;
extern int n4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    FFTSample *out = output;
    for (k = 0; k < n4; k += 4) {
        int idx1 = n2 - k - 1;
        int idx2 = n2 + k;
        int idx3 = n - k - 1;

        // Access in forward order using temporary pointers to promote consecutive access pattern
        FFTSample *p1 = &out[k];
        FFTSample *p2 = &out[idx1 - 3]; // points to n2-k-4
        FFTSample *p3 = &out[idx2];
        FFTSample *p4 = &out[idx3 - 3];

        p1[0] = -p2[3];
        p1[1] = -p2[2];
        p1[2] = -p2[1];
        p1[3] = -p2[0];
        p4[3] = p3[0];
        p4[2] = p3[1];
        p4[1] = p3[2];
        p4[0] = p3[3];
    }
}
