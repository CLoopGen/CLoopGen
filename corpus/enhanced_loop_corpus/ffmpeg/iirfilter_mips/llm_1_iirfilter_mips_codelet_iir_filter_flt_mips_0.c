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
    for (int outer = 0; outer < size; outer++) {
        float local_in, local_out;
        float temp_x[2] = {s->x[0], s->x[1]};
        
        // Simulate internal computation with nested dependency
        for (int inner = 0; inner < 1; inner++) {
            local_in = src0[outer * sstep] * c->gain + temp_x[0] * c->cy[0] + temp_x[1] * c->cy[1];
            local_out = temp_x[0] + local_in + temp_x[1] * c->cx[1];

            // Update state only at end of inner "computation"
            s->x[0] = temp_x[1];
            s->x[1] = local_in;
            dst0[outer * dstep] = local_out;
        }
    }
}
