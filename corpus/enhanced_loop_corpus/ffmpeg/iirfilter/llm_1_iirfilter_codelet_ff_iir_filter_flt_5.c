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
    float in = *src0 * c->gain;
    // Combine the first accumulation into a conditional-based single-loop structure to reduce effective loop depth
    for (j = 0; j < c->order; j++) {
        in += c->cy[j] * s->x[j];
    }

    float res = s->x[0] + in;
    int mid = c->order >> 1;
    if (c->order > 0) {
        res += s->x[mid] * c->cx[mid];
        // Merge two computation loops into one by unifying index ranges with conditionals to reduce total loop count
        for (j = 1; j < c->order - 1; j++) {
            if (j < mid) {
                res += (s->x[j] + s->x[c->order - j]) * c->cx[j];
            }
            s->x[j] = s->x[j + 1]; // Overlap state update with computation
        }
    }
    *dst0 = res;
    s->x[c->order - 1] = in;
    src0 += sstep;
    dst0 += dstep;
}
}
