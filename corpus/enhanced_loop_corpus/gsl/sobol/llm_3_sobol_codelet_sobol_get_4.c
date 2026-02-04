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
    // Variant 2: Strided memory access pattern – process elements in strides of 2 for potential vectorization or prefetching benefits
    // Two separate passes: even indices, then odd indices
    const int base_stride = 2;
    const int num_elements = dimension;
    int *num_vec = s_state->last_numerator_vec;
    int *dir_vec = s_state->v_direction[ell - 1];
    double inv_denom = s_state->last_denominator_inv;

    // First pass: even indices
    for (i_dimension = 0; i_dimension < num_elements; i_dimension += base_stride) {
        const int direction_i = dir_vec[i_dimension];
        const int old_numerator_i = num_vec[i_dimension];
        const int new_numerator_i = old_numerator_i ^ direction_i;
        num_vec[i_dimension] = new_numerator_i;
        v[i_dimension] = new_numerator_i * inv_denom;
    }

    // Second pass: odd indices
    for (i_dimension = 1; i_dimension < num_elements; i_dimension += base_stride) {
        const int direction_i = dir_vec[i_dimension];
        const int old_numerator_i = num_vec[i_dimension];
        const int new_numerator_i = old_numerator_i ^ direction_i;
        num_vec[i_dimension] = new_numerator_i;
        v[i_dimension] = new_numerator_i * inv_denom;
    }
}
