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

uint8_t *dst;
uint64_t pix;
int32_t n;
int32_t row_offset;

uint8_t *dst_buffer;
size_t total_size = 1 << 20; // 1MB data size

void init_vars() {
    row_offset = 8;
    pix = 0xCAFEBABEDEADBEEFULL;
    n = total_size / row_offset;

    dst_buffer = aligned_alloc(64, total_size);
    if (!dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    dst = dst_buffer;
}