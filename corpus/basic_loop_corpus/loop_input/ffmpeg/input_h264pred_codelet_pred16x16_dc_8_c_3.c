#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

ptrdiff_t stride;
int i;
int dc;
uint8_t *src;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    src = (uint8_t *)aligned_alloc(32, data_size);
    if (!src) exit(1);

    stride = 16; // ensures i - stride is within bounds for i in [0,15] and valid memory behind src
    uint8_t *base = src + stride; // shift base so that src[0 - stride] points to valid memory
    memmove(base, src, data_size - stride);
    memset(src, 0, stride); // initialize the preceding segment accessed by negative index
    src = base;

    dc = 0;
}