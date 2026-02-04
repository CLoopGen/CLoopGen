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
extern double sum_den;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = sum_den;
    for (int i = 0; i < iir->nb_ab[1]; i++) {
        local_sum = local_sum + iir->ab[1][i];
    }
    sum_den = local_sum;
}
