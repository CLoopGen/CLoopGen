#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double LPC_TYPE;

int max_order = 32;

LPC_TYPE *ref;
LPC_TYPE *error;
int i;
int j;
LPC_TYPE err;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    ref = (LPC_TYPE*)aligned_alloc(32, max_order * sizeof(LPC_TYPE));
    error = (LPC_TYPE*)aligned_alloc(32, max_order * sizeof(LPC_TYPE));

    for (int idx = 0; idx < max_order; idx++) {
        ref[idx] = 1.0 + idx * 0.01;
        error[idx] = 0.0;
    }

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 1.0;
        gen1[idx] = 1.0;
    }

    err = 1.0;
}