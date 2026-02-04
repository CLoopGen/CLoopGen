#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc1;
uint16_t *src;

void init_vars() {
    stride = 4;
    dc0 = 0;
    dc1 = 0;
    size_t data_size = 1 << 20;
    src = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}