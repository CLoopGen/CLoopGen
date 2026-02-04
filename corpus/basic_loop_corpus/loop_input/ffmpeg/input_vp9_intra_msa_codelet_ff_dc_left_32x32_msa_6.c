#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dst_stride;
uint32_t row;

uint8_t *dst_buffer;
uint8_t global_dst_buffer[16777216]; // 16 MB buffer

void init_vars() {
    dst_stride = 4096;
    dst_buffer = global_dst_buffer;
    dst = dst_buffer;
}