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
    for (int j = 0; j < size; j += 2) {
        float in0, in1;
        float *src_temp = src0 + j * sstep;
        float *dst_temp = dst0 + j * dstep;

        // First iteration of unrolled loop
        if (j < size) {
            in0 = *src_temp * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
            *dst_temp = s->x[0] + in0 + s->x[1] * c->cx[1];
            s->x[0] = s->x[1];
            s->x[1] = in0;
        }

        // Second iteration of unrolled loop
        if (j + 1 < size) {
            in1 = *(src_temp + sstep) * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
            *(dst_temp + dstep) = s->x[0] + in1 + s->x[1] * c->cx[1];
            s->x[0] = s->x[1];
            s->x[1] = in1;
        }
    }
}
