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
for (i = 0; i < size; i++) {
    float temp_in = *src0 * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
    float temp_out = s->x[0] + temp_in + s->x[1] * c->cx[1];
    *dst0 = temp_out;
    s->x[0] = s->x[1];
    s->x[1] = temp_in;
    src0 += sstep;
    dst0 += dstep;
}
}
