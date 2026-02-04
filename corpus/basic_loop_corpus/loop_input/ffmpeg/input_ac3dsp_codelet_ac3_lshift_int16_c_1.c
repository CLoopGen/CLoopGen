#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int len;
unsigned int shift;
uint32_t *src32;
uint32_t mask;
int i;

void init_vars() {
    shift = 3;
    mask = 0x7FFFFFFF;
    len = (1 << 24) / sizeof(uint32_t); // ~16.7M elements, ~64MB total data

    src32 = (uint32_t *)aligned_alloc(32, len * sizeof(uint32_t));
    if (!src32) {
        exit(1);
    }

    for (unsigned int j = 0; j < len; ++j) {
        src32[j] = rand();
    }
}