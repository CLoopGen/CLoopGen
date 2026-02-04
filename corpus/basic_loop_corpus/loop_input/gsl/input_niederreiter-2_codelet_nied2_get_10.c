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
double *v;
double recip = 1.0 / 4096.0;
nied2_state_t *n_state;
unsigned int i_dim;

void init_vars() {
    v = (double*)calloc(dimension, sizeof(double));
    n_state = (nied2_state_t*)malloc(sizeof(nied2_state_t));
    if (!v || !n_state) {
        exit(1);
    }

    n_state->sequence_count = 0;
    for (int i = 0; i < 12; i++) {
        n_state->nextq[i] = i + 1;
    }
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 12; j++) {
            n_state->cj[i][j] = (i + 1) * (j + 1);
        }
    }
}