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
    size = 6710886;  // Approximately 256MB of input data (6.7M elements * sizeof(float) ~ 256MB)

    c = malloc(sizeof(struct FFIIRFilterCoeffs));
    c->order = 2;
    c->gain = 1.0f;

    c->cx = malloc(2 * sizeof(int));
    c->cx[0] = 0;
    c->cx[1] = 1;

    c->cy = malloc(2 * sizeof(float));
    c->cy[0] = 0.5f;
    c->cy[1] = -0.25f;

    s = malloc(sizeof(struct FFIIRFilterState) + 1 * sizeof(float));  // x[0], x[1]
    s->x[0] = 0.0f;
    s->x[1] = 0.0f;

    src0 = aligned_alloc(32, size * sizeof(float));
    dst0 = aligned_alloc(32, size * sizeof(float));

    for (int j = 0; j < size; j++) {
        src0[j] = (float)(j % 1000) / 1000.0f;
        dst0[j] = 0.0f;
    }

    sstep = 1;
    dstep = 1;
    i = 0;
}