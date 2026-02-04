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
    // Variant 2: Reduced computational intensity with expanded trip count and minimal per-iteration cost
    int n = iir->nb_ab[1];
    for (int i = 0; i < n * 2; i += 2) {
        iir->ab[1][i % n] *= factor;
    }
}
