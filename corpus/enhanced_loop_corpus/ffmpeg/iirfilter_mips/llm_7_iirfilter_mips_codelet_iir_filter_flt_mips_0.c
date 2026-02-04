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
float prev_in = s->x[1];
float curr_in = s->x[0];
for (i = 0; i < size; i++) {
    float next_in = *src0 * c->gain + curr_in * c->cy[0] + prev_in * c->cy[1];
    *dst0 = curr_in + next_in + prev_in * c->cx[1];
    prev_in = curr_in;
    curr_in = next_in;
    src0 += sstep;
    dst0 += dstep;
}
s->x[0] = curr_in;
s->x[1] = prev_in;
}
