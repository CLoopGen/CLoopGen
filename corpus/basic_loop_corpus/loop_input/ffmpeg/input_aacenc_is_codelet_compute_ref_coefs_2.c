#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float LPC_TYPE;

int max_order = 31;

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
    err = 1.0f;

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 1.0f;
        gen1[idx] = 1.0f;
    }
    for (int idx = 0; idx <= max_order; idx++) {
        ref[idx] = 0.1f * idx;
        if (error)
            error[idx] = 0.0f;
    }
}