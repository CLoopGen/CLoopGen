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
    float in = 0.0f, res = 0.0f;
    if (c->order > 0) {
        in = *src0 * c->gain;
        for (j = 0; j < c->order; j++)
            in += c->cy[j] * s->x[j];
        res = s->x[0] + in;
        if ((c->order >> 1) > 0)
            res += s->x[c->order >> 1] * c->cx[c->order >> 1];
        for (j = 1; j < c->order >> 1; j++) {
            float sum = s->x[j] + s->x[c->order - j];
            res += sum * c->cx[j];
        }
        for (j = 0; j < c->order - 1; j++)
            s->x[j] = s->x[j + 1];
        *dst0 = res;
        s->x[c->order - 1] = in;
    } else {
        *dst0 = *src0 * c->gain;
    }
    src0 += sstep;
    dst0 += dstep;
}
}
