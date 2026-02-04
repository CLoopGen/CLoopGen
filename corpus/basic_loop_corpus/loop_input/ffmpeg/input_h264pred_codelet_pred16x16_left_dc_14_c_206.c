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
uint16_t *src;
uint64_t dcsplat;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime
static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    stride = 16; // Advance by 16 uint16_t elements per iteration (32 bytes)
    dcsplat = 0x0123456789ABCDEFULL;
    src = data_buffer;
}

// Ensure the buffer is large enough for 16 iterations with maximum offset
// Each iteration accesses up to offset +12 (4 uint64 writes), each advancing by 4 uint16_t indices
// Max index: 12 * 4 = 48 uint16_t elements per row, over 16 rows -> 16 * stride must cover at least that
// We set stride to 16 (32 bytes), so we access rows safely within bounds as long as buffer >= 16*stride
// Our buffer has millions of elements, so it's safe.