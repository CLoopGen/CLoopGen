#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

void *dst;
int stride;
int bits;
int i;
int x;
int Ra;
int r;

static uint8_t *data_8;
static uint16_t *data_16;

void init_vars() {
    const size_t target_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate

    bits = rand() % 2 ? 8 : 16; // randomly choose 8 or 16
    Ra = rand(); // initialize Ra with some value

    if (bits == 8) {
        data_8 = aligned_alloc(64, target_size);
        dst = data_8;
    } else {
        data_16 = aligned_alloc(64, target_size);
        dst = data_16;
    }

    stride = (bits == 8) ? 1 : 2; // natural stride based on element size
    x = 0;
    r = target_size / (bits == 8 ? 1 : 2); // number of iterations to cover the buffer
}