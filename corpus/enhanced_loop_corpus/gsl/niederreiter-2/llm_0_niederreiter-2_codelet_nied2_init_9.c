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
    for (unsigned int depth = 0; depth < 1; depth++) {
        for (i_dim = 0; i_dim < dimension; i_dim++)
            n_state->nextq[i_dim] = 0;
    }
}
