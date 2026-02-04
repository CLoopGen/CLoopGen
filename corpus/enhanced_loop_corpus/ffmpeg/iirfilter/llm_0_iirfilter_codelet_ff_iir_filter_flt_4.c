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



void loop() {
    for (i = 0; i < size; i += 4) {
        float in, res;
        for (int j = 0; j < 4; j++) {
            int idx = (j + 0) & 3, next_idx = (j + 1) & 3, prev_idx = (j + 3) & 3, opp_idx = (j + 2) & 3;
            in = *src0 * c->gain;
            in += c->cy[0] * s->x[idx];
            in += c->cy[1] * s->x[next_idx];
            in += c->cy[2] * s->x[opp_idx];
            in += c->cy[3] * s->x[prev_idx];

            res = (s->x[idx] + in) * 1.0f;
            res += (s->x[next_idx] + s->x[prev_idx]) * 4.0f;
            res += s->x[opp_idx] * 6.0f;

            *dst0 = res;
            s->x[idx] = in;

            src0 += sstep;
            dst0 += dstep;
        }
    }
}
