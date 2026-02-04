#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct FFIIRFilterCoeffs {
    int order;
    float gain;
    int *cx;
    float *cy;
};

struct FFIIRFilterState {
    float x[1];
};

struct FFIIRFilterCoeffs *c;
struct FFIIRFilterState *s;
int size;
ptrdiff_t sstep;
ptrdiff_t dstep;
int i;
float *src0;
float *dst0;

void init_vars() {
    const int order = 8;
    const int data_size = 4 << 20; // ~16MB of input data for ~0.01 sec runtime estimate

    c = (struct FFIIRFilterCoeffs *)calloc(1, sizeof(struct FFIIRFilterCoeffs));
    c->order = order;
    c->gain = 1.0f;

    c->cx = (int *)calloc(order, sizeof(int));
    c->cy = (float *)calloc(order, sizeof(float));

    for (int j = 0; j < order; j++) {
        c->cx[j] = 1;
        c->cy[j] = 1.0f / (j + 1);
    }

    s = (struct FFIIRFilterState *)calloc(1, sizeof(struct FFIIRFilterState) + (order - 1) * sizeof(float));
    for (int j = 0; j < order; j++) {
        s->x[j] = 0.0f;
    }

    src0 = (float *)calloc(data_size, sizeof(float));
    dst0 = (float *)calloc(data_size, sizeof(float));
    for (int j = 0; j < data_size; j++) {
        src0[j] = 1.0f;
    }

    size = data_size;
    sstep = 1;
    dstep = 1;
    i = 0;
}