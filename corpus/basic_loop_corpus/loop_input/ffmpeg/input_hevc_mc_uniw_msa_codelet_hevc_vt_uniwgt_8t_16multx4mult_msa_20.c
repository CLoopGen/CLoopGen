#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int32_t src_stride;
uint8_t *dst;
int32_t dst_stride;
int32_t height;
int32_t weightmul16;
uint8_t *src_tmp;
uint8_t *dst_tmp;
int32_t loop_cnt;
int32_t cnt;

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024)

static uint8_t *global_src_buffer;
static uint8_t *global_dst_buffer;

void init_vars() {
    const int approx_ops_per_inner_loop = 16; 
    const double target_time_seconds = 0.01;
    const double ops_per_second = 1e9;
    const int total_ops = (int)(target_time_seconds * ops_per_second / approx_ops_per_inner_loop);

    height = ((total_ops / 4) * 4) & ~3;
    if (height < 4) height = 4;

    weightmul16 = 16;

    src_stride = (height > 0) ? (TOTAL_BYTES / height) : 64;
    if (src_stride < 16) src_stride = 16;

    dst_stride = src_stride;

    size_t src_size = (size_t)height * (size_t)src_stride + 7 * (size_t)src_stride + 16;
    size_t dst_size = (size_t)height * (size_t)dst_stride + 7 * (size_t)dst_stride + 16;

    global_src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    global_dst_buffer = (uint8_t*)aligned_alloc(32, dst_size);

    if (!global_src_buffer || !global_dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    memset(global_src_buffer, 0x5A, src_size);
    memset(global_dst_buffer, 0, dst_size);

    src = global_src_buffer;
    dst = global_dst_buffer;

    src_tmp = NULL;
    dst_tmp = NULL;
    loop_cnt = 0;
    cnt = 0;
}