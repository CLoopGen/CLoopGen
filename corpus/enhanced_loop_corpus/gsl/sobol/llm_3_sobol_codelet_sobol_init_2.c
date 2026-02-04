#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int sequence_count;
    double last_denominator_inv;
    int last_numerator_vec[40];
    int v_direction[30][40];
} sobol_state_t;

extern unsigned int dimension;
extern sobol_state_t *s_state;
extern unsigned int i_dim;
extern int j;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use consecutive memory access by flipping loop order (loop interchange)
    // This improves spatial locality by accessing memory in row-major order consecutively
    ell = 1 << (30 - 1 - 1);  // Precompute ell as power of two corresponding to initial j
    for (i_dim = 0; i_dim < dimension; i_dim++) {
        for (j = 30 - 1 - 1; j >= 0; j--) {
            s_state->v_direction[j][i_dim] *= ell;
            ell >>= 1;  // Halve ell each time j decreases (reverse accumulation)
        }
        ell = 1 << (30 - 1 - 1);  // Reset ell for next i_dim
    }
}
