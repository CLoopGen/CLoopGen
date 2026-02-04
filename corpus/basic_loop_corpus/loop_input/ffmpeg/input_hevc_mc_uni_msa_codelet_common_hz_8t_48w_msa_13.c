#include <stdint.h>
#include <stdlib.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
uint32_t loop_cnt;

static uint8_t src_buffer[1 << 20]; // 1MB buffer
static uint8_t dst_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    src = src_buffer;
    src_stride = 15; // Small positive stride to stay within bounds over 64 iterations
    dst = dst_buffer;
    dst_stride = 17; // Small positive stride
    loop_cnt = 64;
}