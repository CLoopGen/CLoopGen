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
    for (int j = 0; j <= max_order; j++) {
        autoc[j] = (LPC_TYPE)(j + 1) * 0.5f;
    }
    for (int j = 0; j < 32; j++) {
        gen0[j] = 0.0f;
        gen1[j] = 0.0f;
    }
}