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
float *src_arr = src0;
float *dst_arr = dst0;
ptrdiff_t ss = sstep, ds = dstep;
for (i = 0; i < size; i++) {
    int j;
    float in, res;
    float temp_x[32]; // Assuming max order is 32 for stack usage
    in = (*src_arr) * c->gain;
    for (j = 0; j < c->order; j++)
        in += c->cy[j] * s->x[j];
    res = s->x[0] + in + s->x[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res += (s->x[j] + s->x[c->order - j]) * c->cx[j];
    for (j = 0; j < c->order - 1; j++)
        temp_x[j] = s->x[j + 1];
    *dst_arr = res;
    temp_x[c->order - 1] = in;
    for (j = 0; j < c->order; j++)
        s->x[j] = temp_x[j];
    src_arr += ss;
    dst_arr += ds;
}
}
