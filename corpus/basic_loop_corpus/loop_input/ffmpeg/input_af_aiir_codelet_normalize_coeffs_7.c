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
double sum_num;

static double *ab0_data;
static int ab0_size;

void init_vars() {
    ab0_size = 10000000; // ~80 MB for double data, adjust for ~0.01 sec runtime
    ab0_data = (double *)calloc(ab0_size, sizeof(double));
    if (!ab0_data) exit(1);

    for (int i = 0; i < ab0_size; i++) {
        ab0_data[i] = (double)(i % 1000) / 100.0;
    }

    iir = (IIRChannel *)malloc(sizeof(IIRChannel));
    if (!iir) exit(1);

    iir->nb_ab[0] = ab0_size;
    iir->nb_ab[1] = 0;
    iir->ab[0] = ab0_data;
    iir->ab[1] = NULL;
    iir->g = 1.0;
    iir->cache[0] = NULL;
    iir->cache[1] = NULL;
    iir->biquads = NULL;
    iir->clippings = 0;

    sum_num = 0.0;
}