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
uint64_t dc2splat;
uint16_t *src;

void init_vars() {
    const size_t data_size = 256 * 1024 * sizeof(uint16_t); // ~512KB of data to allow safe access with stride
    src = aligned_alloc(64, data_size);
    if (!src) exit(1);

    stride = 128; 
    dc2splat = 0xCAFEBABEDEADBEEFULL;

    for (int idx = 0; idx < 8 * stride; idx++) {
        src[idx] = (uint16_t)(idx * 0x9E37);
    }
}