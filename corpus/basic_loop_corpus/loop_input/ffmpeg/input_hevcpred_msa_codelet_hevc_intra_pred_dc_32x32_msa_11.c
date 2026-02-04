#include <stdint.h>
#include <stdlib.h>

uint8_t *dst;
int32_t stride;
uint32_t row;

static uint8_t *dst_buffer;
static int32_t buffer_size = 1 << 20; // 1MB of data

void init_vars() {
    dst_buffer = (uint8_t *)aligned_alloc(64, buffer_size);
    dst = dst_buffer;
    stride = 64;
}

__attribute__((destructor))
static void cleanup() {
    free(dst_buffer);
}