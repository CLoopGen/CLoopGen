#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float LPC_TYPE;

LPC_TYPE *autoc;
int max_order;
int i;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(LPC_TYPE);
    autoc = (LPC_TYPE*)aligned_alloc(32, data_size);
    if (!autoc) exit(1);

    max_order = 32;

    for (int j = 0; j < (data_size / sizeof(LPC_TYPE)); j++) {
        autoc[j] = (LPC_TYPE)(j % 1000) / 10.0f;
    }
}