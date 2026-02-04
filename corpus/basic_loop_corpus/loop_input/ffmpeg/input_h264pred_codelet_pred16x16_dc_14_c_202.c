#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int i;
int dc;
uint16_t *src;

void init_vars() {
    stride = 64; // Ensure sufficient spacing to avoid overlap
    dc = 0;

    size_t total_size = 16 * 64 * sizeof(uint16_t); // 16 iterations, max index: -1 + 15*stride
    src = aligned_alloc(64, total_size);
    if (!src) exit(1);

    for (size_t idx = 0; idx < total_size / sizeof(uint16_t); ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}