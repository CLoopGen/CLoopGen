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
    float temp_x[64];  // Assuming max order is <= 64 for stack allocation safety
    int order = c->order < 64 ? c->order : 64;

    for (j = 0; j < order; j++) {
        temp_x[j] = s->x[j];
    }

    in = *src0 * c->gain;
    for (j = 0; j < order; j++) {
        in += c->cy[j] * temp_x[j];
    }

    res = temp_x[0] + in + temp_x[order - 1] * c->cx[0];  // Reinterpret symmetry: use first cx coeff with last state

    for (j = 1; j < order; j++) {
        res += temp_x[j] * c->cx[j % ((order >> 1) + 1)];
    }

    for (j = 0; j < order - 1; j++) {
        s->x[j] = temp_x[j + 1];  // Update state using original values (eliminates WAW and WAR hazards via local copy)
    }
    *dst0 = res;
    s->x[order - 1] = in;

    src0 += sstep;
    dst0 += dstep;
}
}
