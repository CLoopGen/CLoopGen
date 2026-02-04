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
    int shift_val = 1;
    for (state->qbpp = 0; shift_val < state->range; state->qbpp++) {
        shift_val = (1 << state->qbpp);
        if (state->qbpp % 4 == 0) {
            state->run_index[0] += state->T1;
            state->run_index[1] += state->T2;
        }
    }
    if (state->qbpp > 0) state->qbpp--;
}
