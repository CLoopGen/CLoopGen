#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
int i;
uint32_t dc4splat;
uint32_t dc5splat;
uint8_t *src;

void init_vars() {
    // Ensure the data size leads to reasonable execution time (~0.01 sec)
    // We'll allocate enough data so that accesses at i=8 and i=11 are valid
    // Since we access (src + i * stride) and then treat as uint32_t array,
    // we need to ensure sufficient buffer size.

    // Choose stride to be a common line width, e.g., 64 bytes = 16 uint32_t
    stride = 16;

    // Initialize dc values
    dc4splat = 0xdeadbeef;
    dc5splat = 0xc0defeed;

    // Allocate buffer: we access i from 8 to 11 => max offset is 11 * stride + some extra for uint32_t indexing
    // We access ((uint32_t*)(src + i*stride))[0] and [1] => need 2 * sizeof(uint32_t) past i*stride
    size_t required_size = (12 * stride) + (2 * sizeof(uint32_t));
    // Round up to page boundary for safety
    required_size = (required_size + 4095) & ~4095UL;

    src = (uint8_t*)aligned_alloc(32, required_size);
    if (!src) {
        exit(1);
    }
    memset(src, 0, required_size);
}
