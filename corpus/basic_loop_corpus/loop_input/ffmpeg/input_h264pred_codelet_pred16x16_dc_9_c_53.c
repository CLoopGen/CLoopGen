#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride = 16;
int i;
int dc;
uint16_t *src;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16MB of data
    src = (uint16_t*)aligned_alloc(32, data_size);
    if (!src) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx % 32768);
    }
    i = 0;
    dc = 0;
    stride = 16;
}