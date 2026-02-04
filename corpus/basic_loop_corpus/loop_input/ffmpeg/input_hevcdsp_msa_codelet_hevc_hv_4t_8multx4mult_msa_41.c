#include <stdlib.h>
#include <stdint.h>

uint8_t *src;
int32_t src_stride;
int16_t *dst;
int32_t dst_stride;
int32_t height;
int32_t width8mult;
uint32_t loop_cnt;
uint32_t cnt;
uint8_t *src_tmp;
int16_t *dst_tmp;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024)

void init_vars() {
    const int approximate_pixel_count = TOTAL_ELEMENTS / sizeof(uint8_t);
    height = 512;
    width8mult = 1024;
    
    src_stride = width8mult + 32;
    dst_stride = width8mult + 16;

    src = aligned_alloc(32, (size_t)height * src_stride * sizeof(uint8_t));
    dst = aligned_alloc(32, (size_t)height * dst_stride * sizeof(int16_t));

    for (int i = 0; i < height * src_stride; i++) {
        src[i] = rand() & 0xFF;
    }
    for (int i = 0; i < height * dst_stride; i++) {
        dst[i] = rand() & 0xFFFF;
    }

    loop_cnt = 0;
    cnt = 0;
    src_tmp = NULL;
    dst_tmp = NULL;
}