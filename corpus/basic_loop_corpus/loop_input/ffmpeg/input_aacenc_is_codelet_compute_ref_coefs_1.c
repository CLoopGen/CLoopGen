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
    max_order = 32;
    autoc = (LPC_TYPE*)aligned_alloc(32, sizeof(LPC_TYPE) * (max_order + 1));
    for (int idx = 0; idx <= max_order; idx++) {
        autoc[idx] = (LPC_TYPE)(idx + 1) * 0.5f;
    }
    for (int idx = 0; idx < 32; idx++) {
        gen0[idx] = 0.0f;
        gen1[idx] = 0.0f;
    }
}