#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint16_t *src;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(uint16_t);
    src = aligned_alloc(32, data_size);
    stride = 4;
    dc0 = 0;
    dc1 = 0;
    for (int idx = 0; idx < 256 * 1024; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}