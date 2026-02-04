#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t idct_sse2_row_perm[8] = {0, 1, 2, 3, 4, 5, 6, 7};

uint8_t *idct_permutation;

int i;

void init_vars() {
    idct_permutation = (uint8_t *)malloc(64 * sizeof(uint8_t));
    if (!idct_permutation) {
        exit(1);
    }
}