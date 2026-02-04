#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
    if (!ref || !error) {
        exit(1);
    }

    for (int idx = 0; idx < max_order; idx++) {
        ref[idx] = (LPC_TYPE)(idx + 1) * 0.1f;
        error[idx] = 0.0f;
    }

    err = 1.0f;

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = (LPC_TYPE)(idx % 5 + 1) * 0.5f;
        gen1[idx] = (LPC_TYPE)((idx + 1) % 4 + 1) * 0.25f;
    }
}