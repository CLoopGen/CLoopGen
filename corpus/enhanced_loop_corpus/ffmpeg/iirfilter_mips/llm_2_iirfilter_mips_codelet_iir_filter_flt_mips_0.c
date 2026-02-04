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
    // Variant 1: Consecutive memory access with unrolled stride handling
    // Instead of using pointer arithmetic with arbitrary steps, we assume sstep and dstep are multiples of sizeof(float)
    // and access src0 and dst0 in a more cache-friendly, consecutive manner by precomputing indices.
    float *src = src0;
    float *dst = dst0;
    ptrdiff_t src_inc = sstep / sizeof(float);
    ptrdiff_t dst_inc = dstep / sizeof(float);

    for (i = 0; i < size; i++) {
        float in = src[0] * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
        dst[0] = s->x[0] + in + s->x[1] * c->cx[1];
        s->x[0] = s->x[1];
        s->x[1] = in;
        src += src_inc;
        dst += dst_inc;
    }
}
