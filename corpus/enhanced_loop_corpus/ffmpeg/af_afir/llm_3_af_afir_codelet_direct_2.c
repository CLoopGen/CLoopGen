#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

typedef struct FFTComplex {
    FFTSample re;
    FFTSample im;
} FFTComplex;

extern  float *in;
extern  FFTComplex *ir;
extern int len;
extern float *out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (forward sequential) memory access pattern
    // Reorder computation to improve spatial locality in `in` array by iterating
    // over lag indices first and accumulating into `out` with forward references.
    for (int k = 0; k < len; k++) {  // k = n - m => m = n - k
        for (int n = k; n < len; n++) {
            out[n] += ir[n - k].re * in[k];
        }
    }
}
