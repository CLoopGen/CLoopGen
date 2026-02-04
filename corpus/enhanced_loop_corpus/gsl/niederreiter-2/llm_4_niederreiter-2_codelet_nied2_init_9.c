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
extern nied2_state_t *n_state;
extern unsigned int i_dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i_dim = 0; i_dim < dimension; i_dim++) {
        if (n_state->nextq[i_dim] >= 0)
            n_state->nextq[i_dim] = 0;
    }
}
