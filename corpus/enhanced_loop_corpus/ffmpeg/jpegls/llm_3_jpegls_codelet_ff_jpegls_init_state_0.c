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
    int stride = 7; // Strided access pattern
    int offset = state->qbpp % 5; // Dynamic offset based on qbpp
    for (state->qbpp = 0; (1 << state->qbpp) < state->range; state->qbpp++) {
        // Access B array with fixed stride and dynamic offset
        state->B[offset + stride * (state->qbpp % 50)] ^= state->A[state->qbpp % 367];
        state->N[state->qbpp % 367] += state->C[state->qbpp % 365];
    }
}
