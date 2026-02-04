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
    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * 32);
    if (!src) exit(1);
    for (int j = 0; j < 32; j++) {
        src[j] = 1;
    }
}