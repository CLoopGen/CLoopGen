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
    for (i = 0; i < 367; i++) {
        int temp = state->range + 32 >> 6;
        state->A[i] = temp > 2 ? temp : 2;
        if (i % 4 == 0) {
            state->N[i] = 2;
        } else {
            state->N[i] = 1;
        }
    }
}
