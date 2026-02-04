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
    k = 0;
    unsigned int n_val = state->N[Q];
    unsigned int a_val = state->A[Q];
    if (n_val == 0 || a_val == 0) {
        return;
    }
    for (; (n_val << k) < a_val; k++) {
        if (k >= 31) break;
    }
}
