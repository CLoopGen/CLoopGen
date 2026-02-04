#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *cache;
int bits;
int i;
int low;
int high;

static uint8_t *internal_cache;
static size_t cache_size = 1 << 20; // 1MB data size

void init_vars() {
    internal_cache = (uint8_t *)calloc(cache_size, sizeof(uint8_t));
    if (!internal_cache) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < cache_size; idx++) {
        internal_cache[idx] = rand() % 256;
    }

    cache = internal_cache;
    bits = 128;
    low = 0;
    high = cache_size - 1;
}