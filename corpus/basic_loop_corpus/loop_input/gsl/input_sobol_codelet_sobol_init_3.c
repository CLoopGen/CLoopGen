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
sobol_state_t *s_state;
unsigned int i_dim;

void init_vars() {
    s_state = (sobol_state_t*)aligned_alloc(64, sizeof(sobol_state_t));
    
    if (!s_state) {
        exit(1);
    }
    
    s_state->sequence_count = 0;
    s_state->last_denominator_inv = 1.0;
    
    for (int i = 0; i < 40; i++) {
        s_state->last_numerator_vec[i] = 0;
        for (int j = 0; j < 30; j++) {
            s_state->v_direction[j][i] = 0;
        }
    }
}