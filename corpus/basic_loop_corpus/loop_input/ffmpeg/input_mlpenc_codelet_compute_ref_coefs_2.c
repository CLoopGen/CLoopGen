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
    ref = (LPC_TYPE*)calloc(max_order + 1, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(max_order + 1, sizeof(LPC_TYPE));

    for (int k = 0; k < 32; k++) {
        gen0[k] = (LPC_TYPE)(k + 1) / 32.0f;
        gen1[k] = (LPC_TYPE)(k + 1) / 16.0f;
    }

    err = 1.0f;

    for (int k = 0; k < max_order; k++) {
        ref[k] = (LPC_TYPE)(k % 32) * 0.01f;
    }
}