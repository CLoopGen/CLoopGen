#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

ptrdiff_t stride;
int i;
int dc0;
int dc2;
uint16_t *src;

void init_vars() {
    const size_t total_size = 1 << 20; // 1MB of data
    src = (uint16_t*)aligned_alloc(32, total_size);
    
    if (!src) exit(1);

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = (total_size / sizeof(uint16_t)) / 8;
    dc0 = 0;
    dc2 = 0;
}