#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

ptrdiff_t stride;
int i;
int dc0;
int dc2;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    src = (uint8_t *)aligned_alloc(64, data_size);
    if (!src) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = (uint8_t)(idx & 0xFF);
    }

    stride = 65536; // Ensure sufficient spacing to prevent out-of-bounds access
    dc0 = 0;
    dc2 = 0;
}