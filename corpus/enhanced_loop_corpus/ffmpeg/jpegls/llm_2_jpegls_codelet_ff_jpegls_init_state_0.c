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
    int idx = 0;
    for (state->qbpp = 0; (1 << state->qbpp) < state->range; state->qbpp++) {
        // Introduce consecutive memory access to array A with unrolled access pattern
        state->A[idx] += 1;
        state->A[idx + 1] += 2;
        state->A[idx + 2] += 3;
        idx += 3;
        if (idx >= 360) idx = 0; // Prevent overflow
    }
}
