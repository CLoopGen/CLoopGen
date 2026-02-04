#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct BiquadContext {
    double a[3];
    double b[3];
    double i1;
    double i2;
    double o1;
    double o2;
} BiquadContext;

typedef struct IIRChannel {
    int nb_ab[2];
    double *ab[2];
    double g;
    double *cache[2];
    BiquadContext *biquads;
    int clippings;
} IIRChannel;

extern IIRChannel *iir;
extern double factor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulating non-contiguous or reordered access)
    // Assume an auxiliary index array is available; here we simulate it via arithmetic.
    // Access elements in reverse order — a form of indirect access pattern
    int n = iir->nb_ab[1];
    for (int j = 0; j < n; j++) {
        int i = n - 1 - j;  // Reverse indexing
        iir->ab[1][i] *= factor;
    }
}
