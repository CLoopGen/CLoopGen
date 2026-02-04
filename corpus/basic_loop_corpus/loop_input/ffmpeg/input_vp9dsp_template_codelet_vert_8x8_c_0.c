#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

ptrdiff_t stride;
uint8_t *dst;
uint32_t p4a;
uint32_t p4b;
int y;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB to target ~0.01 sec runtime
static uint8_t global_data[DATA_SIZE];

void init_vars() {
    // Initialize scalar values
    p4a = 0xCAFEBABE;
    p4b = 0xDEADBEEF;

    // Set stride to 8 bytes per row (two 32-bit writes per iteration)
    stride = 8;

    // Ensure dst points within bounds: we write 8 bytes per iteration, 8 iterations -> 64 bytes needed
    // So as long as DATA_SIZE >= 64 and we start early enough, we're safe
    dst = global_data;

    // Optional: initialize memory to known state
    memset(global_data, 0, sizeof(global_data));
}