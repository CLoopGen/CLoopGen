#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
uint8_t *last;
int bpp;
int i;
int p;

static uint8_t *internal_dst;
static uint8_t *internal_src;
static uint8_t *internal_last;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; 

    internal_dst = aligned_alloc(32, data_size);
    internal_src = aligned_alloc(32, data_size);
    internal_last = aligned_alloc(32, data_size);

    dst = internal_dst;
    src = internal_src;
    last = internal_last;

    for (size_t idx = 0; idx < data_size; idx++) {
        internal_src[idx] = rand() & 0xFF;
        internal_last[idx] = rand() & 0xFF;
    }

    bpp = 1; 
    while (bpp < (int)data_size) {
        bpp <<= 1;
    }
    bpp >>= 1;
    if (bpp == 0) bpp = 1;
}