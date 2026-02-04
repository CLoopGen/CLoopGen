#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride = 16; // Ensures alignment and spacing for 2x uint64_t per row
int i;
uint64_t dc0splat = 0xDEADBEEFCAFEBABEULL;
uint64_t dc1splat = 0xBAADF00DBAADF00DULL;
uint16_t *src;

void init_vars() {
    const size_t total_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_elements = total_size / sizeof(uint16_t);
    src = aligned_alloc(64, total_size);
    if (!src) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (size_t idx = 0; idx < num_elements; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}