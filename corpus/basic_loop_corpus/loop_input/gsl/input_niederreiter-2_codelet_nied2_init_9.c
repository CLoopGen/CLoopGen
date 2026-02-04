#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int sequence_count;
    int cj[31][12];
    int nextq[12];
} nied2_state_t;

unsigned int dimension = 12;
nied2_state_t *n_state;
unsigned int i_dim;

void init_vars() {
    n_state = (nied2_state_t *)calloc(1, sizeof(nied2_state_t));
    if (!n_state) {
        exit(1);
    }
    n_state->sequence_count = 0;
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 12; j++) {
            n_state->cj[i][j] = 0;
        }
    }
    for (int i = 0; i < 12; i++) {
        n_state->nextq[i] = 0;
    }
}