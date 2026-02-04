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
extern int Q;
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int n_val = state->N[Q];
    int shifted;
    for (k = 0; k < 64; k++) {
        shifted = n_val << k;
        if (shifted >= temp) break;
        state->A[k % 367] += shifted & 0xF;
        state->B[k % 367] ^= (shifted >> 4);
    }
}
