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

ptrdiff_t stride;
int i;
uint64_t dc0splat;
uint64_t dc1splat;
uint16_t *src;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of data
    const size_t num_elements = data_size / sizeof(uint16_t);
    
    src = aligned_alloc(64, data_size);
    if (!src) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; ++idx) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }

    stride = 16; 
    dc0splat = 0x0123012301230123ULL;
    dc1splat = 0xABCDAABCDAABCDAULL;
}

__attribute__((constructor))
static void constructor_call_init_vars() {
    init_vars();
}