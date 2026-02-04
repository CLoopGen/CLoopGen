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
        float in = *src0 * c->gain;
        for (int j = 0; j < c->order && j < 2; j++) {
            in += s->x[j] * c->cy[j];
        }
        float out = s->x[0] + in;
        for (int j = 1; j < c->order && j < 2; j++) {
            out += s->x[j] * c->cx[j];
        }
        *dst0 = out;

        s->x[0] = s->x[1];
        s->x[1] = in;

        src0 += sstep;
        dst0 += dstep;
    }
}
