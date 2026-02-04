#include <stdint.h>
#include <stdlib.h>

uint8_t *out;
int i;
int stride;
uint32_t col;

uint8_t *out_buffer;

void init_vars() {
    // Allocate a buffer large enough to allow several writes with stride
    // Assuming worst case: 4 iterations, so we need at least 4 * stride bytes
    // Choose stride such that total access is safe; set buffer size accordingly
    const size_t buffer_size = 1 << 20; // ~1MB of data for sufficient runtime (~0.01 sec estimate)
    
    out_buffer = (uint8_t*)aligned_alloc(32, buffer_size);
    if (!out_buffer) exit(1);

    // Ensure output pointer is aligned to uint32_t boundary
    out = out_buffer;

    // Set stride to a reasonable value: 4 bytes per step (sequential)
    stride = sizeof(uint32_t);

    // Initialize col with non-zero pattern for visibility
    col = 0xDEADBEEF;
}