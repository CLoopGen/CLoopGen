#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern u_int i;
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Simulate indirect access by treating 'dim' elements as accessed via reverse order indices
    u_int idx;
    for (i = 0; i < dim; i++) {
        idx = dim - 1 - i;  // Reverse indexing: access from end to start
        if (!((b_ent[idx]).re == 0. && (b_ent[idx]).im == 0.))
            break;
        else
            out_ent[idx].re = out_ent[idx].im = 0.;
    }
}
