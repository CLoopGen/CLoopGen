#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t w;
int acc;
int i;

static uint8_t *internal_src;
static uint8_t *internal_dst;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    internal_src = (uint8_t *)aligned_alloc(32, data_size);
    internal_dst = (uint8_t *)aligned_alloc(32, data_size);

    if (!internal_src || !internal_dst) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        internal_src[idx] = (uint8_t)(idx % 251); // deterministic non-zero pattern
    }

    src = internal_src;
    dst = internal_dst;
    w = (ptrdiff_t)data_size;
    acc = 0;
    i = 0;
}