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
int Q;
int k;

void init_vars() {
    state = (JLSState*)calloc(1, sizeof(JLSState));
    if (!state) exit(1);

    Q = 0;
    k = 0;

    for (int i = 0; i < 367; i++) {
        state->A[i] = (i + 1) * 3;
        state->N[i] = (i + 1) * 2;
    }
}