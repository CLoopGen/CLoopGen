#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc0;
int dc2;
uint16_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 2^20 bytes
    src = aligned_alloc(32, data_size);
    if (!src) exit(1);

    stride = (data_size / sizeof(uint16_t)) / 8; // Ensure sufficient spacing

    for (size_t idx = 0; idx < data_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    dc0 = 0;
    dc2 = 0;
}