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
// Outer loop split: process two iterations at a time to reduce loop depth effect and change nesting structure
for (i = 0; i < size; i += 2) {
    int j;
    float in1, res1, in2, res2;
    
    // First iteration
    in1 = *src0 * c->gain;
    for (j = 0; j < c->order; j++)
        in1 += c->cy[j] * s->x[j];
    res1 = s->x[0] + in1 + s->x[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res1 += (s->x[j] + s->x[c->order - j]) * c->cx[j];
    for (j = 0; j < c->order - 1; j++)
        s->x[j] = s->x[j + 1];
    *dst0 = res1;
    s->x[c->order - 1] = in1;

    // Prepare for second iteration if exists
    if (i + 1 >= size) break;

    src0 += sstep;
    dst0 += dstep;

    in2 = *src0 * c->gain;
    for (j = 0; j < c->order; j++)
        in2 += c->cy[j] * s->x[j];
    res2 = s->x[0] + in2 + s->x[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res2 += (s->x[j] + s->x[c->order - j]) * c->cx[j];
    for (j = 0; j < c->order - 1; j++)
        s->x[j] = s->x[j + 1];
    *dst0 = res2;
    s->x[c->order - 1] = in2;

    src0 += sstep;
    dst0 += dstep;
}
}
