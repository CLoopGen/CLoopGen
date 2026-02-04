#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

ptrdiff_t stride = 16;
int i;
int dc;
uint8_t *src;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data
    src = (uint8_t *)aligned_alloc(32, data_size);
    if (!src) exit(1);

    for (size_t idx = 0; idx < data_size; ++idx) {
        src[idx] = rand() & 0xFF;
    }

    // Ensure that i - stride is within bounds when i < 16
    // So we require at least |stride| elements before the first accessed index.
    // We make src point to the middle of allocated memory to allow negative offsets.
    uint8_t *base = src;
    src += stride; // Now src[-stride..] maps to base[0..]

    dc = 0;
}