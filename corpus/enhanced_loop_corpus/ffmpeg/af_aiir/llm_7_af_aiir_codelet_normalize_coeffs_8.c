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
    double *ab1 = iir->ab[1];
    int nb_ab1 = iir->nb_ab[1];
    double acc = 1.0;
    for (int i = 0; i < nb_ab1; i++) {
        ab1[i] *= factor * acc;
        acc = ab1[i] > 0.0 ? acc : acc + 1.0; // Introduce artificial loop-carried dependency (WAW and RAW)
    }
}
