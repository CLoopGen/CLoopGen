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
extern double sum_num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    int trip_count = iir->nb_ab[0] * 2;
    for (int i = 0; i < trip_count; i++) {
        int idx = i / 2;
        local_sum += iir->ab[0][idx] * (i & 1 ? 1.1 : 0.9);
    }
    sum_num += local_sum;
}
