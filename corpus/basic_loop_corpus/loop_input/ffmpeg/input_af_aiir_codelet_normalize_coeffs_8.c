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
double factor;

static double *ab1_data;
static BiquadContext *biquads_data;

void init_vars() {
    // Allocate biquads_data to ensure valid pointer
    biquads_data = calloc(1, sizeof(BiquadContext));

    // Set data size to achieve ~0.01s runtime: assume processing 1M doubles takes ~0.01s on modern CPU
    size_t data_size = 1 << 20; // 1 million elements

    ab1_data = calloc(data_size, sizeof(double));
    if (!ab1_data) {
        exit(1);
    }

    // Initialize iir structure
    iir = malloc(sizeof(IIRChannel));
    if (!iir) {
        exit(1);
    }

    iir->nb_ab[0] = 0;
    iir->nb_ab[1] = data_size;
    iir->ab[0] = NULL;
    iir->ab[1] = ab1_data;
    iir->g = 1.0;
    iir->cache[0] = NULL;
    iir->cache[1] = NULL;
    iir->biquads = biquads_data;
    iir->clippings = 0;

    factor = 1.5;
}