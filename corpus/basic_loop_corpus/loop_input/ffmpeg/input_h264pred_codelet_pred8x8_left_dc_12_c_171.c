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

ptrdiff_t stride = 16; 
int i = 0;
uint64_t dc0splat = 0xCAFEBABEDEADBEEFULL;
uint16_t *src = NULL;

static uint16_t *src_buffer = NULL;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; 
    src_buffer = aligned_alloc(64, data_size);
    if (!src_buffer) {
        exit(1);
    }
    src = src_buffer;
}