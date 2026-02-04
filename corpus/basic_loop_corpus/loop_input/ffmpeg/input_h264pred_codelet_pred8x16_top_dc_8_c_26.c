#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint8_t *src;

void init_vars() {
    stride = 16;
    dc0 = 0;
    dc1 = 0;
    src = (uint8_t *)aligned_alloc(32, 256 * 1024 * 1024);
    if (!src) exit(1);
    for (size_t idx = 0; idx < 256 * 1024 * 1024; ++idx) {
        src[idx] = (uint8_t)(idx % 256);
    }
}