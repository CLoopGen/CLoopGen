#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

uint8_t *dst;
uint8_t *src;
ptrdiff_t stride;
int32_t loop_cnt;

static uint8_t *internal_src_buffer;
static uint8_t *internal_dst_buffer;
static size_t total_data_size = 64 * (1 << 20); // 64 MB for sufficient workload

void init_vars() {
    internal_src_buffer = (uint8_t *)aligned_alloc(32, total_data_size);
    internal_dst_buffer = (uint8_t *)aligned_alloc(32, total_data_size);

    if (!internal_src_buffer || !internal_dst_buffer) {
        exit(1);
    }

    src = internal_src_buffer;
    dst = internal_dst_buffer;

    stride = 16;

    loop_cnt = 0;
}