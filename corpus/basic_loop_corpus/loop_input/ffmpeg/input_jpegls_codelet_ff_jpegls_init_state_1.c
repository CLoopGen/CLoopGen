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
int i;

void init_vars() {
    state = (JLSState*)malloc(sizeof(JLSState));
    if (!state) {
        exit(1);
    }

    state->T1 = 0;
    state->T2 = 0;
    state->T3 = 0;

    for (int j = 0; j < 367; j++) {
        state->A[j] = 0;
        state->B[j] = 0;
        state->N[j] = 0;
    }

    for (int j = 0; j < 365; j++) {
        state->C[j] = 0;
    }

    for (int j = 0; j < 4; j++) {
        state->run_index[j] = 0;
    }

    state->limit = 367;
    state->reset = 0;
    state->bpp = 8;
    state->qbpp = 8;
    state->maxval = 255;
    state->range = 256;
    state->near = 0;
    state->twonear = 0;

    i = 0;
}