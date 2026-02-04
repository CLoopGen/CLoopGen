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

extern sobol_state_t *s_state;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access via flattened indexing to simulate linear memory traversal
    // Treat the 2D array as a 1D array to enforce strictly consecutive memory writes, improving spatial locality.
    // We map index [k][0] to flat index [k * 40 + 0], ensuring sequential access pattern.
    volatile int *base = &(s_state->v_direction[0][0]);
    for (k = 0; k < 30; k++) {
        base[k * 40] = 1;
    }
}
