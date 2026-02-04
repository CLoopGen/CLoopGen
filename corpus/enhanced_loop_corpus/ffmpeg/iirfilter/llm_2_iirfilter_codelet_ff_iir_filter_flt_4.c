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


extern  struct FFIIRFilterCoeffs *c;
extern struct FFIIRFilterState *s;
extern int size;
extern ptrdiff_t sstep;
extern ptrdiff_t dstep;
extern int i;
extern  float *src0;
extern float *dst0;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < size; i += 4) {
        float in, res;
        // Consecutive memory access: unroll and access src0 and dst0 in increasing order with unit stride
        // State indices rotated using modulo arithmetic to simulate sliding window

        // Iteration 0
        in = src0[0] * c->gain + c->cy[0] * s->x[0] + c->cy[1] * s->x[1] + c->cy[2] * s->x[2] + c->cy[3] * s->x[3];
        res = (s->x[0] + in) * 1 + (s->x[1] + s->x[3]) * 4 + s->x[2] * 6;
        dst0[0] = res;
        s->x[0] = in;

        // Iteration 1
        in = src0[sstep] * c->gain + c->cy[0] * s->x[1] + c->cy[1] * s->x[2] + c->cy[2] * s->x[3] + c->cy[3] * s->x[0];
        res = (s->x[1] + in) * 1 + (s->x[2] + s->x[0]) * 4 + s->x[3] * 6;
        dst0[dstep] = res;
        s->x[1] = in;

        // Iteration 2
        in = src0[2*sstep] * c->gain + c->cy[0] * s->x[2] + c->cy[1] * s->x[3] + c->cy[2] * s->x[0] + c->cy[3] * s->x[1];
        res = (s->x[2] + in) * 1 + (s->x[3] + s->x[1]) * 4 + s->x[0] * 6;
        dst0[2*dstep] = res;
        s->x[2] = in;

        // Iteration 3
        in = src0[3*sstep] * c->gain + c->cy[0] * s->x[3] + c->cy[1] * s->x[0] + c->cy[2] * s->x[1] + c->cy[3] * s->x[2];
        res = (s->x[3] + in) * 1 + (s->x[0] + s->x[2]) * 4 + s->x[1] * 6;
        dst0[3*dstep] = res;
        s->x[3] = in;

        // Update pointers once per 4-element block
        src0 += 4 * sstep;
        dst0 += 4 * dstep;
    }
}
