#include <stdlib.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
int32_t loop_cnt;

void init_vars() {
    const int total_height = 1 << 14; // 16384 rows
    const int width = 128;            // 128 elements per row

    src_stride = width;
    dst_stride = width;
    height = total_height;

    uint8_t *src_data = (uint8_t*)aligned_alloc(32, (size_t)total_height * src_stride * sizeof(uint8_t));
    int16_t *dst_data = (int16_t*)aligned_alloc(32, (size_t)total_height * dst_stride * sizeof(int16_t));

    for (int i = 0; i < total_height * width; ++i) {
        src_data[i] = (uint8_t)(i & 0xFF);
        dst_data[i] = (int16_t)(i & 0x7FF);
    }

    src = src_data;
    dst = dst_data;
}