#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width;
uint32_t loop_cnt;
uint32_t cnt;
uint8_t *src_tmp;
int16_t *dst_tmp;

static uint8_t *src_buffer;
static int16_t *dst_buffer;

void init_vars() {
    width = 1024;
    height = 1024;
    src_stride = width + 32;
    dst_stride = width + 16;

    size_t src_size = (size_t)(height + 7) * src_stride;
    size_t dst_size = (size_t)(height + 7) * dst_stride;

    src_buffer = (uint8_t*)calloc(src_size, sizeof(uint8_t));
    dst_buffer = (int16_t*)calloc(dst_size, sizeof(int16_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    src = src_buffer + 0;
    dst = dst_buffer + 0;

    src_tmp = NULL;
    dst_tmp = NULL;
    loop_cnt = 0;
    cnt = 0;
}