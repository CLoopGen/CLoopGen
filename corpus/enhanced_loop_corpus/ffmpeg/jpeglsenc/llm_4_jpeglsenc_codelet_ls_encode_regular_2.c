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
extern int Q;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; (state->N[Q] << k) < state->A[Q]; k++) {
        if (k >= 31) break;
    }
}
