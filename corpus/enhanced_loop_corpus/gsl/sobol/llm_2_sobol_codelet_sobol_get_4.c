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
extern double *v;
extern sobol_state_t *s_state;
extern unsigned int i_dimension;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via pointer arithmetic to improve cache locality
    int *numerator_ptr = s_state->last_numerator_vec;
    double inv_denom = s_state->last_denominator_inv;
    int *direction_row = s_state->v_direction[ell - 1];
    for (i_dimension = 0; i_dimension < dimension; i_dimension++) {
        const int direction_i = *(direction_row + i_dimension);
        const int old_numerator_i = *(numerator_ptr + i_dimension);
        const int new_numerator_i = old_numerator_i ^ direction_i;
        *(numerator_ptr + i_dimension) = new_numerator_i;
        v[i_dimension] = new_numerator_i * inv_denom;
    }
}
