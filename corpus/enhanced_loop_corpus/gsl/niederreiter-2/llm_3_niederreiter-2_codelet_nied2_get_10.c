#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int sequence_count;
    int cj[31][12];
    int nextq[12];
} nied2_state_t;

extern unsigned int dimension;
extern double *v;
extern  double recip;
extern nied2_state_t *n_state;
extern unsigned int i_dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic for improved locality
    double *v_ptr = v;
    int (*nextq_ptr)[12] = &(n_state->nextq);
    for (i_dim = 0; i_dim < dimension; i_dim++) {
        *v_ptr++ = (*nextq_ptr)[i_dim] * recip;
    }
}
