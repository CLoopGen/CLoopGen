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
if (n4 > 0) { // Decreased effective loop depth by replacing with a single-level conditional and unrolled-like structure (partial unrolling simulation)
    int i = 0;
    for (; i < n4; i++) {
        output[i] = -output[n2 - i - 1];
        output[n - i - 1] = output[n2 + i];
    }
}
}
