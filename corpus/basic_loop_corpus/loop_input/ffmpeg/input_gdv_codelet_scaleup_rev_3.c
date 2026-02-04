#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int w;
int x;

static uint8_t *internal_src;
static uint8_t *internal_dst;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec on modern CPU)

    internal_src = aligned_alloc(32, data_size);
    internal_dst = aligned_alloc(32, data_size);

    if (!internal_src || !internal_dst) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        internal_src[i] = rand() & 0xFF;
    }

    dst = internal_dst;
    src = internal_src;
    w = data_size - 1; // ensures (w-1) starts near end, and loop condition safe
}