#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride_dst = 512;
ptrdiff_t stride_src = 512;
int y;
uint16_t *dst;
uint16_t *src;
int init_y = 0;
int height = 1024;
int save_upper_left = 1;
int save_lower_left = 1;

void init_vars() {
    const size_t total_size = 1024 * 1024 * 2; // ~2MB of data (enough for ~0.01s runtime)
    const size_t num_elements = total_size / sizeof(uint16_t);

    height = num_elements / stride_dst;
    if (height > 32768) height = 32768;

    dst = aligned_alloc(64, height * stride_dst * sizeof(uint16_t));
    src = aligned_alloc(64, height * stride_src * sizeof(uint16_t));

    for (int i = 0; i < height * stride_dst; i++) {
        dst[i] = 0;
    }
    for (int i = 0; i < height * stride_src; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }

    init_y = 0;
    save_upper_left = 1;
    save_lower_left = 1;
    stride_dst = 512;
    stride_src = 512;
}