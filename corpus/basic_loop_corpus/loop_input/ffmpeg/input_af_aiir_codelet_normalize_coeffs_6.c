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

IIRChannel *iir;
double sum_den;

static double *ab_1_data;
static int nb_ab_1_size = 10000000; // ~80 MB of data for ab[1]

void init_vars() {
    ab_1_data = (double *)calloc(nb_ab_1_size, sizeof(double));
    if (!ab_1_data) exit(1);

    for (int i = 0; i < nb_ab_1_size; i++) {
        ab_1_data[i] = 1.0 + (i % 100) * 0.01;
    }

    iir = (IIRChannel *)malloc(sizeof(IIRChannel));
    if (!iir) exit(1);

    iir->nb_ab[0] = 0;
    iir->nb_ab[1] = nb_ab_1_size;
    iir->ab[0] = NULL;
    iir->ab[1] = ab_1_data;
    iir->g = 1.0;
    iir->cache[0] = NULL;
    iir->cache[1] = NULL;
    iir->biquads = NULL;
    iir->clippings = 0;

    sum_den = 0.0;
}