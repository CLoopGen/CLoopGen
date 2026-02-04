#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static size_t data_size = 1 << 20; // 1MB data size

void init_vars() {
    src = (uint8_t *)aligned_alloc(32, data_size);
    if (!src) exit(1);
    stride = 32;
    dc0 = 0xdeadbeefU;
}