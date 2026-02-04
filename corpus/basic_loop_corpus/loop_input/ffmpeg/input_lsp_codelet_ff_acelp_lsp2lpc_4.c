#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *lp;
int lp_half_order;
int i;
int f1[11];
int f2[11];

void init_vars() {
    lp_half_order = 10;

    for (i = 0; i < 11; i++) {
        f1[i] = (i + 1) * 3;
        f2[i] = (i + 1) * 7;
    }

    lp = aligned_alloc(2, sizeof(int16_t) * ((lp_half_order << 1) + 1));
}

__attribute__((destructor))
static void cleanup() {
    free(lp);
}