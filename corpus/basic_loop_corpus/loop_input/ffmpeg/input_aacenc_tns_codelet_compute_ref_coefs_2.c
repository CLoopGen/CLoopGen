#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
    ref = (LPC_TYPE*)aligned_alloc(32, sizeof(LPC_TYPE) * (max_order + 1));
    error = (LPC_TYPE*)aligned_alloc(32, sizeof(LPC_TYPE) * (max_order + 1));

    for (int idx = 0; idx <= max_order; idx++) {
        ref[idx] = (LPC_TYPE)(1.0f / (idx + 1));
        if (error) error[idx] = 0.0f;
    }

    err = 1.0f;
    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = (LPC_TYPE)((idx % 2) ? 0.5f : -0.5f);
        gen1[idx] = (LPC_TYPE)((idx % 3) ? 0.25f : -0.25f);
    }
}