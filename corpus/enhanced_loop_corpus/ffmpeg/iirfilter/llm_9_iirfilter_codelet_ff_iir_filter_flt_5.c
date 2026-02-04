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
    int j, k;
    float in1, in2, res1, res2;
    float temp_x1[16], temp_x2[16];
    if (i + 1 >= size) break;

    in1 = src0[0] * c->gain;
    in2 = src0[sstep/sizeof(float)] * c->gain;

    for (j = 0; j < c->order; j++) {
        in1 += c->cy[j] * s->x[j];
        temp_x1[j] = s->x[j];
    }
    for (j = 0; j < c->order - 1; j++) {
        temp_x2[j] = temp_x1[j + 1];
    }
    temp_x2[c->order - 1] = in1;

    for (k = 0; k < c->order; k++) {
        in2 += c->cy[k] * temp_x2[k];
    }

    res1 = temp_x1[0] + in1;
    res2 = temp_x2[0] + in2;

    for (j = 1; j < c->order >> 1; j++) {
        res1 += (temp_x1[j] + temp_x1[c->order - j]) * c->cx[j];
        res2 += (temp_x2[j] + temp_x2[c->order - j]) * c->cx[j];
    }

    for (j = 0; j < c->order - 1; j++)
        s->x[j] = (j < c->order - 2) ? temp_x2[j + 1] : in2;

    dst0[0] = res1;
    dst0[dstep/sizeof(float)] = res2;

    src0 += 2 * sstep;
    dst0 += 2 * dstep;
    s->x[c->order - 1] = in2;
}
}
