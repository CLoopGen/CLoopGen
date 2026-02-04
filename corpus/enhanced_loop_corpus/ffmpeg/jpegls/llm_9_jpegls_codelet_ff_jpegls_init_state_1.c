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
    int factor = (state->range + 32) >> 6;
    int clamp = (factor > 2) ? factor : 2;
    for (i = 0; i < 184; i++) {
        state->A[2*i] = clamp;
        state->A[2*i + 1] = clamp;
        state->N[2*i] = 1;
        state->N[2*i + 1] = 1;
    }
    if (i == 184) {
        state->A[366] = clamp;
        state->N[366] = 1;
    }
}
