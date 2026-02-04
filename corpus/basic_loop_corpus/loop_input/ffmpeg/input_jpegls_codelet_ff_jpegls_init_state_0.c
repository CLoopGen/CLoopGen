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

JLSState *state;

void init_vars() {
    state = (JLSState *)calloc(1, sizeof(JLSState));
    if (!state) exit(1);

    state->T1 = 1;
    state->T2 = 2;
    state->T3 = 3;
    for (int i = 0; i < 367; i++) {
        state->A[i] = i % 256;
        state->B[i] = (i + 10) % 256;
        if (i < 365) state->C[i] = (i + 20) % 256;
        state->N[i] = (i + 30) % 256;
    }
    state->limit = 1000;
    state->reset = 0;
    state->bpp = 8;
    state->qbpp = 0;
    state->maxval = 255;
    state->range = 512;
    state->near = 0;
    state->twonear = 0;
    for (int i = 0; i < 4; i++) {
        state->run_index[i] = i;
    }
}