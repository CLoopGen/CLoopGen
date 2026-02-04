#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    stride = 16;
    dc = 0;
    src = (uint16_t*)aligned_alloc(32, 256 * 1024 * 1024);
    if (!src) exit(1);
    for (size_t idx = 0; idx < (256 * 1024 * 1024) / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx % 32768);
    }
}