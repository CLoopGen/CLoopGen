#include <stdint.h>
#include <stdlib.h>

uint8_t *idct_permutation;
int i;

void init_vars() {
    idct_permutation = (uint8_t*)malloc(64 * sizeof(uint8_t));
    if (!idct_permutation) exit(1);
    i = 0;
}