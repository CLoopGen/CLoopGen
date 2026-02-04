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
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    for (i = 0; i < 367; i += 2) {
        state->A[i] = ((state->range + 32 >> 6) > (2) ? (state->range + 32 >> 6) : (2));
        state->N[i] = 1;
    }
    for (i = 1; i < 367; i += 2) {
        state->A[i] = ((state->range + 32 >> 6) > (2) ? (state->range + 32 >> 6) : (2));
        state->N[i] = 1;
    }
}
