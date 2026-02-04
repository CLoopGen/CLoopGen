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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    state->A[0] = ((state->range + 32 >> 6) > (2) ? (state->range + 32 >> 6) : (2));
    state->N[0] = 1;
    for (i = 1; i < 367; i++) {
        state->A[i] = state->A[i-1]; // Introduce WAW and RAW dependency: each A[i] depends on previous A[i-1]
        state->N[i] = state->N[i-1] + 1; // Introduce loop-carried RAW dependency: N[i] depends on prior N[i-1]
    }
}
