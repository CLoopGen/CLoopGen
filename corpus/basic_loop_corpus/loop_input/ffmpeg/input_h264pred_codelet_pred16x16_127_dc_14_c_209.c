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
uint16_t *src;

#define DATA_SIZE (128 * 1024 * 1024) // 128MB of data
static uint16_t data_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    for (size_t idx = 0; idx < DATA_SIZE / sizeof(uint16_t); ++idx) {
        data_buffer[idx] = 0;
    }
    src = data_buffer;
    stride = 16; // ensures 16-byte alignment per iteration, safe for 4x av_alias64 writes
    i = 0;
}