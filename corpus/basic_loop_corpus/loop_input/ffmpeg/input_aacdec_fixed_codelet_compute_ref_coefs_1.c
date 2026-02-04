#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int LPC_TYPE;

LPC_TYPE *autoc;
int max_order;
int i;
LPC_TYPE gen0[32];
LPC_TYPE gen1[32];

void init_vars() {
    max_order = 32;
    autoc = (LPC_TYPE*)malloc((max_order + 1) * sizeof(LPC_TYPE));
    if (!autoc) {
        exit(1);
    }
    for (int j = 0; j <= max_order; j++) {
        autoc[j] = rand();
    }
}