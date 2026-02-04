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
    for (i = 0; i < size; i++) {
        float in, res;
        int idx = i % 4;
        int next_idx = (idx + 1) % 4;
        int prev_idx = (idx + 3) % 4;
        int opp_idx = (idx + 2) % 4;

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
