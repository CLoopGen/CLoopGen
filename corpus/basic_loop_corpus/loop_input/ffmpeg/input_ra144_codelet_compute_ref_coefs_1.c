#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float LPC_TYPE;

int max_order = 512;

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
        ref[idx] = (LPC_TYPE)(idx + 1) * 0.01f;
        if (error) error[idx] = 0.0f;
    }

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = (LPC_TYPE)(idx % 8) * 0.1f;
        gen1[idx] = (LPC_TYPE)((idx % 8) + 1) * 0.1f;
    }

    err = 1.0f;
    i = 0;
    j = 0;
}