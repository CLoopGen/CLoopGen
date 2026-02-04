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

unsigned int dimension = 20;
sobol_state_t *s_state;
unsigned int i_dim;
int j;
int ell;

void init_vars() {
    // Allocate s_state on heap
    s_state = (sobol_state_t*)calloc(1, sizeof(sobol_state_t));
    
    // Initialize structure fields
    s_state->sequence_count = 0;
    s_state->last_denominator_inv = 1.0;
    
    for (int i = 0; i < 40; i++) {
        s_state->last_numerator_vec[i] = i + 1;
    }
    
    // Initialize v_direction with non-zero values to avoid trivial optimization
    for (int i = 0; i < 30; i++) {
        for (int k = 0; k < 40; k++) {
            s_state->v_direction[i][k] = (i + 1) * (k + 1);
        }
    }
    
    // Set initial value for ell to ensure meaningful computation
    ell = 1;
}