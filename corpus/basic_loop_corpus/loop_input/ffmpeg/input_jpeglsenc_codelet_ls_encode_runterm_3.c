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
int k;
int Q;
int temp;

void init_vars() {
    state = (JLSState*)calloc(1, sizeof(JLSState));
    if (!state) exit(1);

    Q = 183; 
    temp = 1000000;

    for (int i = 0; i < 367; i++) {
        state->N[i] = (i + 1) * 54321 % 97; 
    }

    state->N[Q] = 10;

    k = 0;
}

void loop();