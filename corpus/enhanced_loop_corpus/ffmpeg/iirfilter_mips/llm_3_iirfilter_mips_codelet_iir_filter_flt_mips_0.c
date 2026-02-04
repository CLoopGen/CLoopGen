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
    // Variant 2: Indirect (indexed) memory access using array indexing instead of pointer arithmetic
    // We convert the stepped pointer updates into indexed access via integer offsets
    // This simulates indirect access patterns that might arise from scatter/gather operations
    for (i = 0; i < size; i++) {
        ptrdiff_t src_idx = (char*)src0 - (char*)s + i * sstep;  // Simulated offset-based index
        ptrdiff_t dst_idx = (char*)dst0 - (char*)s + i * dstep;

        // Convert byte offset to float index assuming base alignment
        float *src_ptr = (float*)((char*)s + src_idx);
        float *dst_ptr = (float*)((char*)s + dst_idx);

        float in = *src_ptr * c->gain + s->x[0] * c->cy[0] + s->x[1] * c->cy[1];
        *dst_ptr = s->x[0] + in + s->x[1] * c->cx[1];
        s->x[0] = s->x[1];
        s->x[1] = in;
    }
}
