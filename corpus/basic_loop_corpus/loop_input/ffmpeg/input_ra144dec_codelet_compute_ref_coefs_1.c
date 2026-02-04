#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float LPC_TYPE;

int max_order;
LPC_TYPE *ref;
LPC_TYPE *error;
int i;
int j;
LPC_TYPE err;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    max_order = 32;

    ref = (LPC_TYPE*)aligned_alloc(32, max_order * sizeof(LPC_TYPE));
    error = (LPC_TYPE*)aligned_alloc(32, max_order * sizeof(LPC_TYPE));

    for (int k = 0; k < max_order; k++) {
        ref[k] = (LPC_TYPE)(k + 1) * 0.1f;
        error[k] = 0.0f;
    }

    for (int k = 0; k < 32; k++) {
        gen0[k] = (LPC_TYPE)(k % 5) * 0.2f;
        gen1[k] = (LPC_TYPE)((k % 7) % 5) * 0.15f;
    }

    i = 0;
    j = 0;
    err = 1.0f;
}