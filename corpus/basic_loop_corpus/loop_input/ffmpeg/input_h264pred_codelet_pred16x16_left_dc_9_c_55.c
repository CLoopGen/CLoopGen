#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // ~2MB of data (1M elements * 2 bytes)
    src = aligned_alloc(32, data_size * sizeof(uint16_t));
    stride = 64; // Ensure safe access with stride
    dc = 0;

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}