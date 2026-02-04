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
    int j;
    float in, res;
    float *x_ptr = s->x;
    float *cy_ptr = c->cy;
    in = *src0 * c->gain;
    for (j = 0; j < c->order; j++)
        in += cy_ptr[j] * x_ptr[j];
    res = x_ptr[0] + in + x_ptr[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res += (x_ptr[j] + x_ptr[c->order - j]) * c->cx[j];
    for (j = 0; j < c->order - 1; j++)
        x_ptr[j] = x_ptr[j + 1];
    *dst0 = res;
    x_ptr[c->order - 1] = in;
    src0 += sstep;
    dst0 += dstep;
}
}
