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
    // Variant 1: Consecutive memory access with array indexing (instead of pointer arithmetic)
    float *src = src0;
    float *dst = dst0;
    for (i = 0; i < size; i++) {
        float in = src[i * sstep] * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
        dst[i * dstep] = s->x[0] + in + s->x[1] * c->cx[1];
        s->x[0] = s->x[1];
        s->x[1] = in;
    }
}
