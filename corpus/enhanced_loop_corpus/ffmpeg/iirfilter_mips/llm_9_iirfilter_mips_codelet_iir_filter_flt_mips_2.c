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
for (i = 0; i < size; i += 2) {
    int j;
    float in0, in1, res0, res1;
    float temp_x0[32], temp_x1[32];
    for (j = 0; j < c->order; j++) {
        temp_x0[j] = s->x[j];
        temp_x1[j] = (j + 1 < c->order) ? s->x[j + 1] : *(src0 + sstep) * c->gain;
    }

    in0 = *src0 * c->gain;
    for (j = 0; j < c->order; j++)
        in0 += c->cy[j] * temp_x0[j];
    res0 = temp_x0[0] + in0 + temp_x0[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res0 += (temp_x0[j] + temp_x0[c->order - j]) * c->cx[j];

    in1 = *(src0 + sstep) * c->gain;
    for (j = 0; j < c->order; j++)
        in1 += c->cy[j] * temp_x1[j];
    res1 = temp_x1[0] + in1 + temp_x1[c->order >> 1] * c->cx[c->order >> 1];
    for (j = 1; j < c->order >> 1; j++)
        res1 += (temp_x1[j] + temp_x1[c->order - j]) * c->cx[j];

    for (j = 0; j < c->order - 2; j++)
        s->x[j] = s->x[j + 2];
    if (size - i > 1) {
        s->x[c->order - 2] = in0;
        s->x[c->order - 1] = in1;
        *dst0 = res0;
        *(dst0 + dstep) = res1;
        src0 += 2 * sstep;
        dst0 += 2 * dstep;
    } else {
        s->x[c->order - 1] = in0;
        *dst0 = res0;
        src0 += sstep;
        dst0 += dstep;
    }
}
}
