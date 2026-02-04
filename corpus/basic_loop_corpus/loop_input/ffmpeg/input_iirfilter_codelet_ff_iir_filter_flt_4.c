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
    const int data_size = 64 * 1024 * 1024; // ~64M elements to target ~0.01 sec on modern CPU
    size = data_size / 4 * 4; // Ensure divisible by 4 for the loop unrolling

    src0 = (float *)aligned_alloc(32, sizeof(float) * size);
    dst0 = (float *)aligned_alloc(32, sizeof(float) * size);
    s = (struct FFIIRFilterState *)aligned_alloc(32, sizeof(float) * 4);
    c = (struct FFIIRFilterCoeffs *)malloc(sizeof(struct FFIIRFilterCoeffs));
    float *cy_data = (float *)aligned_alloc(32, sizeof(float) * 4);

    c->order = 4;
    c->gain = 0.5f;
    c->cx = NULL;
    c->cy = cy_data;
    c->cy[0] = 1.0f;
    c->cy[1] = -0.5f;
    c->cy[2] = 0.25f;
    c->cy[3] = -0.125f;

    s->x[0] = 0.0f;
    s->x[1] = 0.0f;
    s->x[2] = 0.0f;
    s->x[3] = 0.0f;

    sstep = 1;
    dstep = 1;

    for (int j = 0; j < size; j++) {
        src0[j] = (float)(j % 1000) / 1000.0f;
    }
}