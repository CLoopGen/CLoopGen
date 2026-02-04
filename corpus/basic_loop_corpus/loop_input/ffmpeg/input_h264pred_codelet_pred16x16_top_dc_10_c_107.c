#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    stride = 16;
    dc = 0;
    src = (uint16_t*)aligned_alloc(32, 256 * 1024 * 1024);
    if (!src) exit(1);
    for (int j = 0; j < (256 * 1024 * 1024) / sizeof(uint16_t); j++) {
        src[j] = (uint16_t)(j % 32768);
    }
}