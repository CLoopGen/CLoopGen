#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef float LPC_TYPE;

int max_order = 256;

LPC_TYPE *ref;
LPC_TYPE *error;
int i;
int j;
LPC_TYPE err;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    const size_t ref_size = max_order + 1;
    const size_t error_size = max_order + 1;

    ref = (LPC_TYPE*)calloc(ref_size, sizeof(LPC_TYPE));
    error = (LPC_TYPE*)calloc(error_size, sizeof(LPC_TYPE));

    if (!ref || !error) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 1.0f + idx * 0.1f;
        gen1[idx] = 2.0f + idx * 0.2f;
    }

    err = 1.0f;

    for (int idx = 0; idx < ref_size; idx++) {
        ref[idx] = 0.1f * (idx + 1);
    }
}