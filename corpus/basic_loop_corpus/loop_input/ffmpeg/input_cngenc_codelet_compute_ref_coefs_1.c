#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

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
    ref = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));

    for (int k = 0; k < 32; k++) {
        gen0[k] = (LPC_TYPE)(k + 1) * 0.1f;
        gen1[k] = (LPC_TYPE)(k + 1) * 0.2f;
    }

    err = 1.0f;

    if (ref) {
        ref[0] = 0.5f;
    }
}