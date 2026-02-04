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
    size = 64 * 1024 * 1024;  // Approximate data size for ~0.01 sec runtime

    sstep = 1;
    dstep = 1;

    c = (struct FFIIRFilterCoeffs *)malloc(sizeof(struct FFIIRFilterCoeffs));
    c->order = 2;
    c->gain = 1.0f;

    c->cx = (int *)malloc(2 * sizeof(int));
    c->cx[0] = 0;
    c->cx[1] = 1;

    c->cy = (float *)malloc(2 * sizeof(float));
    c->cy[0] = 0.5f;
    c->cy[1] = -0.25f;

    s = (struct FFIIRFilterState *)malloc(sizeof(struct FFIIRFilterState) + sizeof(float)); // x[0], x[1]
    s->x[0] = 0.0f;
    ((float *)(s->x))[1] = 0.0f;  // s->x[1]

    src0 = (float *)aligned_alloc(32, size * sizeof(float));
    dst0 = (float *)aligned_alloc(32, size * sizeof(float));

    for (int j = 0; j < size; j++) {
        src0[j] = (float)(j % 1000) / 1000.0f;
        dst0[j] = 0.0f;
    }

    i = 0;
}