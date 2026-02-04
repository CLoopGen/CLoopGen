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
    autoc = aligned_alloc(32, data_size);
    if (!autoc) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(LPC_TYPE); ++idx) {
        autoc[idx] = (LPC_TYPE)(idx % 1000) / 100.0f;
    }

    max_order = 32;
}