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
    FFTSample *out = output;
    int offset1, offset2;
    for (k = 0; k < n4; k++) {
        offset1 = n2 - k - 1;
        offset2 = n - k - 1;
        out[k] = -out[offset1];
        out[offset2] = out[n2 + k];
    }
}
