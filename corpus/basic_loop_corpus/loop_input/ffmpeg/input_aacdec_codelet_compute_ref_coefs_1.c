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
    ref = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(max_order, sizeof(LPC_TYPE));

    if (!ref || !error) {
        exit(1);
    }

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 1.0f;
        gen1[idx] = 1.0f;
    }

    err = 1.0f;
}