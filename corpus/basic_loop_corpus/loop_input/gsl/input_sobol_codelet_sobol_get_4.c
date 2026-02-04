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

unsigned int dimension = 40;
double *v;
sobol_state_t *s_state;
unsigned int i_dimension;
int ell = 1;

void init_vars() {
    // Allocate and initialize v array
    v = (double*)aligned_alloc(32, sizeof(double) * dimension);
    
    // Allocate and initialize sobol state
    s_state = (sobol_state_t*)aligned_alloc(32, sizeof(sobol_state_t));
    s_state->sequence_count = 0;
    s_state->last_denominator_inv = 1.0 / (double)(1ULL << 31);
    
    // Initialize last_numerator_vec to zero
    for (int i = 0; i < 40; i++) {
        s_state->last_numerator_vec[i] = 0;
    }
    
    // Initialize v_direction with non-zero test values
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 40; j++) {
            s_state->v_direction[i][j] = (i + 1) * (j + 1);
        }
    }
    
    // Set ell to valid index (1-based indexing used in original)
    ell = 1;
}