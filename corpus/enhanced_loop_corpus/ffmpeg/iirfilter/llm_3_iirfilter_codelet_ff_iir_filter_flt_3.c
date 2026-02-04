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
    // Variant 2: Strided access using indirect indexing via index array (simulating non-unit stride or gather pattern)
    // Assume auxiliary index arrays are available: use indirect addressing for src and dst
    // For realism, simulate precomputed index strides as offsets
    ptrdiff_t *src_indices = (ptrdiff_t*)malloc(size * sizeof(ptrdiff_t));
    ptrdiff_t *dst_indices = (ptrdiff_t*)malloc(size * sizeof(ptrdiff_t));
    
    for (int j = 0; j < size; j++) {
        src_indices[j] = j * sstep;
        dst_indices[j] = j * dstep;
    }

    for (i = 0; i < size; i++) {
        float in = *(src0 + src_indices[i]) * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
        *(dst0 + dst_indices[i]) = s->x[0] + in + s->x[1] * c->cx[1];
        s->x[0] = s->x[1];
        s->x[1] = in;
    }

    free(src_indices);
    free(dst_indices);
}
