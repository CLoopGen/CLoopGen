#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct JLSState {
    int T1;
    int T2;
    int T3;
    int A[367];
    int B[367];
    int C[365];
    int N[367];
    int limit;
    int reset;
    int bpp;
    int qbpp;
    int maxval;
    int range;
    int near;
    int twonear;
    int run_index[4];
} JLSState;

extern JLSState *state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int qbpp_limit = state->range;
    for (state->qbpp = 0; (1 << state->qbpp) < qbpp_limit && state->qbpp < 32; state->qbpp++) {
        state->T1 += state->A[state->qbpp % 367] * state->B[state->qbpp % 367];
        state->T2 += state->C[state->qbpp % 365] + state->N[state->qbpp % 367];
    }
}
