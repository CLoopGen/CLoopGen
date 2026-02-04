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



void loop() {
    // Strided memory access: traverse N[] with a fixed stride of 2
    int stride = 2;
    int base = Q;
    int max_iter = (367 - base + stride - 1) / stride;
    for (k = 0; k < max_iter; k++) {
        int idx = base + k * stride;
        if (idx >= 367) break;
        if ((state->N[idx] << k) >= temp) break;
    }
}
