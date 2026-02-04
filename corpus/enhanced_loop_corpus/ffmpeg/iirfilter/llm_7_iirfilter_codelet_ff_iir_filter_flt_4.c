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
for (i = 0; i < size; i += 4) {
    float temp_x[4];
    float in, res;

    // Introduce artificial loop-carried dependency via temporary buffer
    temp_x[0] = s->x[0];
    temp_x[1] = s->x[1];
    temp_x[2] = s->x[2];
    temp_x[3] = s->x[3];

    // Modify data flow: make each iteration depend on prior computed 'in' values
    in = *src0 * c->gain + c->cy[0] * temp_x[0] + c->cy[1] * temp_x[1] + c->cy[2] * temp_x[2] + c->cy[3] * temp_x[3];
    res = (temp_x[0] + in) * 1 + (temp_x[1] + temp_x[3]) * 4 + temp_x[2] * 6;
    *dst0 = res;
    s->x[0] = in;
    src0 += sstep;
    dst0 += dstep;

    // Create RAW dependency: current 'in' depends on previous updated state
    in = *src0 * c->gain + c->cy[0] * s->x[0] + c->cy[1] * temp_x[2] + c->cy[2] * temp_x[3] + c->cy[3] * temp_x[0];
    res = (temp_x[1] + in) * 1 + (temp_x[2] + temp_x[0]) * 4 + temp_x[3] * 6;
    *dst0 = res;
    s->x[1] = in;
    src0 += sstep;
    dst0 += dstep;

    // Strengthen loop-carried chain: use updated s->x[1] in next computation
    in = *src0 * c->gain + c->cy[0] * s->x[1] + c->cy[1] * temp_x[3] + c->cy[2] * temp_x[0] + c->cy[3] * temp_x[1];
    res = (temp_x[2] + in) * 1 + (temp_x[3] + temp_x[1]) * 4 + temp_x[0] * 6;
    *dst0 = res;
    s->x[2] = in;
    src0 += sstep;
    dst0 += dstep;

    // Final stage with full dependency on prior updates
    in = *src0 * c->gain + c->cy[0] * s->x[2] + c->cy[1] * temp_x[0] + c->cy[2] * temp_x[1] + c->cy[3] * temp_x[2];
    res = (temp_x[3] + in) * 1 + (temp_x[0] + temp_x[2]) * 4 + temp_x[1] * 6;
    *dst0 = res;
    s->x[3] = in;
    src0 += sstep;
    dst0 += dstep;
}
}
