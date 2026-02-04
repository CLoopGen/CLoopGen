#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;

void init_vars() {
    width = 64 * 1024 * 1024 / sizeof(int32_t);  // ~256 MB of total data (3 arrays), ~85MB each

    b0 = aligned_alloc(32, width * sizeof(int32_t));
    b1 = aligned_alloc(32, width * sizeof(int32_t));
    b2 = aligned_alloc(32, width * sizeof(int32_t));

    if (!b0 || !b1 || !b2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (i = 0; i < width; i++) {
        b0[i] = (int32_t)(i * 3 + 1);
        b1[i] = (int32_t)(i * 7 + 5);
        b2[i] = (int32_t)(i * 11 + 3);
    }
}