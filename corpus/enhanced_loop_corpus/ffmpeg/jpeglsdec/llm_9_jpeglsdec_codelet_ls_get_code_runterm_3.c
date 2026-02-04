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
extern int k;
extern int temp;
extern int Q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (temp > 1000) ? 2 : 1;
    for (k = 0; k < 10 && ((unsigned int)state->N[Q] << (k * step)) < temp; k += step) {
        state->T3 = (state->A[k] + state->B[k]) >> state->near;
        if (state->T3 > state->maxval) {
            state->T3 = state->maxval;
        }
        state->run_index[k % 4] = state->T3;
    }
    if (k >= 10) k = 9;
}
