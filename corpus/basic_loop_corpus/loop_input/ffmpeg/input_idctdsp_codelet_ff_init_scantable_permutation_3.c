#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *idct_permutation;
int i;

void init_vars() {
    idct_permutation = (uint8_t *)aligned_alloc(64, 64 * sizeof(uint8_t));
    if (!idct_permutation) exit(1);
}

void loop(); // Forward declaration

__attribute__((constructor))
static void setup() {
    init_vars();
    loop();
}