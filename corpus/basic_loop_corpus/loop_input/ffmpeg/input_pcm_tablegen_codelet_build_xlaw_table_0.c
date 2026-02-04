#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *linear_to_xlaw;
int mask;
int j;

void init_vars() {
    size_t total_size = 16777216; // 16 MB
    linear_to_xlaw = (uint8_t *)aligned_alloc(32, total_size);
    if (!linear_to_xlaw) exit(1);

    for (size_t i = 0; i < total_size; i++) {
        linear_to_xlaw[i] = 0;
    }

    mask = 42;
    j = 0;
}