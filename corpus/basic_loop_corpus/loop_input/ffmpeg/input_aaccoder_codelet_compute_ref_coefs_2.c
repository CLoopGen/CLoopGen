#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float LPC_TYPE;

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
        ref[idx] = 0.1f + idx * 0.01f;
        error[idx] = 0.0f;
    }

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 0.5f + idx * 0.02f;
        gen1[idx] = 0.6f + idx * 0.03f;
    }

    err = 1.0f;
}