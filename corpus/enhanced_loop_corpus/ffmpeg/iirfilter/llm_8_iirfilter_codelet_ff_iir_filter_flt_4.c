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



void loop(){
for (i = 0; i < size; i += 8) {
    float in0, in1, in2, in3, res;
    // Unrolled with 8 iterations, increasing computational density

    in0 = *src0 * c->gain + c->cy[0] * s->x[0] + c->cy[1] * s->x[1] + c->cy[2] * s->x[2] + c->cy[3] * s->x[3];
    res = (s->x[0] + in0) * 1 + (s->x[1] + s->x[3]) * 4 + s->x[2] * 6;
    *dst0 = res;
    s->x[0] = in0;
    src0 += sstep;
    dst0 += dstep;

    in1 = *src0 * c->gain + c->cy[0] * s->x[1] + c->cy[1] * s->x[2] + c->cy[2] * s->x[3] + c->cy[3] * s->x[0];
    res = (s->x[1] + in1) * 1 + (s->x[2] + s->x[0]) * 4 + s->x[3] * 6;
    *dst0 = res;
    s->x[1] = in1;
    src0 += sstep;
    dst0 += dstep;

    in2 = *src0 * c->gain + c->cy[0] * s->x[2] + c->cy[1] * s->x[3] + c->cy[2] * s->x[0] + c->cy[3] * s->x[1];
    res = (s->x[2] + in2) * 1 + (s->x[3] + s->x[1]) * 4 + s->x[0] * 6;
    *dst0 = res;
    s->x[2] = in2;
    src0 += sstep;
    dst0 += dstep;

    in3 = *src0 * c->gain + c->cy[0] * s->x[3] + c->cy[1] * s->x[0] + c->cy[2] * s->x[1] + c->cy[3] * s->x[2];
    res = (s->x[3] + in3) * 1 + (s->x[0] + s->x[2]) * 4 + s->x[1] * 6;
    *dst0 = res;
    s->x[3] = in3;
    src0 += sstep;
    dst0 += dstep;

    // Additional 4 unrolled steps to increase arithmetic intensity
    in0 = *src0 * c->gain + c->cy[0] * s->x[0] + c->cy[1] * s->x[1] + c->cy[2] * s->x[2] + c->cy[3] * s->x[3];
    res = (s->x[0] + in0) * 1 + (s->x[1] + s->x[3]) * 4 + s->x[2] * 6;
    *dst0 = res;
    s->x[0] = in0;
    src0 += sstep;
    dst0 += dstep;

    in1 = *src0 * c->gain + c->cy[0] * s->x[1] + c->cy[1] * s->x[2] + c->cy[2] * s->x[3] + c->cy[3] * s->x[0];
    res = (s->x[1] + in1) * 1 + (s->x[2] + s->x[0]) * 4 + s->x[3] * 6;
    *dst0 = res;
    s->x[1] = in1;
    src0 += sstep;
    dst0 += dstep;

    in2 = *src0 * c->gain + c->cy[0] * s->x[2] + c->cy[1] * s->x[3] + c->cy[2] * s->x[0] + c->cy[3] * s->x[1];
    res = (s->x[2] + in2) * 1 + (s->x[3] + s->x[1]) * 4 + s->x[0] * 6;
    *dst0 = res;
    s->x[2] = in2;
    src0 += sstep;
    dst0 += dstep;

    in3 = *src0 * c->gain + c->cy[0] * s->x[3] + c->cy[1] * s->x[0] + c->cy[2] * s->x[1] + c->cy[3] * s->x[2];
    res = (s->x[3] + in3) * 1 + (s->x[0] + s->x[2]) * 4 + s->x[1] * 6;
    *dst0 = res;
    s->x[3] = in3;
    src0 += sstep;
    dst0 += dstep;
}
}
