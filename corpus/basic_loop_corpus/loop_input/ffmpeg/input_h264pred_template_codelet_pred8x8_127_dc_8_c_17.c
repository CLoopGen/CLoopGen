#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
int i;
uint32_t a;
uint8_t *src;

void init_vars() {
    // Set stride to 8 bytes to allow two uint32_t writes per row without overlap
    stride = 8;

    // Initialize 'a' with a non-zero value for meaningful store
    a = 0xDEADBEEF;

    // Allocate approximately 16 MB of data: 8 rows * (stride) * N, but we only use 8 iterations
    // We allocate enough so that 8 rows with given stride are safe
    size_t total_size = 8 * stride;
    src = aligned_alloc(32, total_size);
    if (!src) {
        exit(1);
    }

    // Initialize allocated memory to zero
    for (size_t j = 0; j < total_size; j++) {
        src[j] = 0;
    }
}

// Explicitly define all external variables