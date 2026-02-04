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
    // Variant 2: Consecutive memory access - iterate over a local window of values starting at Q
    int base = Q;
    int i;
    for (i = 0; i < 10 && (base + i) < 367; i++) {
        k = i;
        if ((state->N[base + i] << k) >= state->A[base + i])
            break;
    }
    k = i;
}
