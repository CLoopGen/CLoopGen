#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with pointer arithmetic)
    // Assume auxiliary index array exists: extern u_int *indices; (precomputed reverse order)
    // Since we cannot introduce new globals, simulate indirect access via arithmetic transformation
    // Here: access elements in reverse order but through a virtual "permuted" layout: i XOR 1
    for (i = dim - 1; i >= 0; i--) {
        u_int idx = i ^ 1; // Simple bit-flip for indirect-like pattern (keeps locality)
        if (idx >= dim) continue; // Skip out-of-bounds due to XOR
        if (!((b_ent[idx]).re == 0. && (b_ent[idx]).im == 0.)) {
            break;
        } else {
            out_ent[idx].re = out_ent[idx].im = 0.;
        }
    }
    // Final pass to ensure all trailing elements (in original order) are zeroed if not broken early
    for (i = dim - 1; i >= 0; i--) {
        if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
            break;
        else
            out_ent[i].re = out_ent[i].im = 0.;
    }
}
