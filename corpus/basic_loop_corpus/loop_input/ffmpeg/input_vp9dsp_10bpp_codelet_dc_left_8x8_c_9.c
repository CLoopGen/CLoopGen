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
uint16_t *dst;
uint64_t dc = 0x0102030405060708ULL;
int y;

void init_vars() {
    const size_t total_size = 16 * 8; // Enough for 8 rows with stride 16 (each row accesses up to offset 7)
    dst = aligned_alloc(64, total_size * sizeof(uint16_t));
    if (!dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dc = 0x0102030405060708ULL;
    stride = 16;
}