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
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2 for consecutive updates
    int n = iir->nb_ab[1];
    int i = 0;
    // Process pairs with stride of 2: access even indices first
    for (i = 0; i + 1 < n; i += 2) {
        iir->ab[1][i]     *= factor;
        iir->ab[1][i + 1] *= factor;
    }
    // Handle remaining element if count is odd
    if (i < n) {
        iir->ab[1][i] *= factor;
    }
}
