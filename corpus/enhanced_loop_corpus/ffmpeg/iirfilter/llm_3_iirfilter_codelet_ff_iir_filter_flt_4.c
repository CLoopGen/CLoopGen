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
    // Indirect memory access via index array (simulating gather/scatter pattern)
    // Assume auxiliary index arrays exist: src_idx[i], dst_idx[i] for indirect addressing
    // Since we cannot modify global declarations, we simulate static indexing behavior

    // Define local offset mapping to simulate irregular but deterministic access
    int offsets[4] = {0, 1, 3, 2}; // Example of non-consecutive, strided-like access pattern

    for (i = 0; i < size; i += 4) {
        float in, res;
        ptrdiff_t so0 = offsets[0] * sstep;
        ptrdiff_t so1 = offsets[1] * sstep;
        ptrdiff_t so2 = offsets[2] * sstep;
        ptrdiff_t so3 = offsets[3] * sstep;
        ptrdiff_t do0 = offsets[0] * dstep;
        ptrdiff_t do1 = offsets[1] * dstep;
        ptrdiff_t do2 = offsets[2] * dstep;
        ptrdiff_t do3 = offsets[3] * dstep;

        // Use indirect-like access through computed pointer offsets
        in = *(src0 + so0) * c->gain + c->cy[0] * s->x[0] + c->cy[1] * s->x[1] + c->cy[2] * s->x[2] + c->cy[3] * s->x[3];
        res = (s->x[0] + in) * 1 + (s->x[1] + s->x[3]) * 4 + s->x[2] * 6;
        *(dst0 + do0) = res;
        s->x[0] = in;

        in = *(src0 + so1) * c->gain + c->cy[0] * s->x[1] + c->cy[1] * s->x[2] + c->cy[2] * s->x[3] + c->cy[3] * s->x[0];
        res = (s->x[1] + in) * 1 + (s->x[2] + s->x[0]) * 4 + s->x[3] * 6;
        *(dst0 + do1) = res;
        s->x[1] = in;

        in = *(src0 + so2) * c->gain + c->cy[0] * s->x[2] + c->cy[1] * s->x[3] + c->cy[2] * s->x[0] + c->cy[3] * s->x[1];
        res = (s->x[2] + in) * 1 + (s->x[3] + s->x[1]) * 4 + s->x[0] * 6;
        *(dst0 + do2) = res;
        s->x[2] = in;

        in = *(src0 + so3) * c->gain + c->cy[0] * s->x[3] + c->cy[1] * s->x[0] + c->cy[2] * s->x[1] + c->cy[3] * s->x[2];
        res = (s->x[3] + in) * 1 + (s->x[0] + s->x[2]) * 4 + s->x[1] * 6;
        *(dst0 + do3) = res;
        s->x[3] = in;

        // Advance base pointers by total block step
        src0 += 4 * sstep;
        dst0 += 4 * dstep;
    }
}
