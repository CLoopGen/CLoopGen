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

#define DATA_SIZE (16 * 1024 * 1024)  // 16 MB of data
static uint16_t buffer[DATA_SIZE];

void init_vars() {
    src = buffer;
    stride = 16;  // Ensure each iteration advances by 16 bytes (8 uint16_t elements)
    i = 0;
}