#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int32_t stride;
int32_t v_cnt;
int32_t idx0;
int32_t fact_val0;
int32_t idx1;
int32_t fact_val1;
int32_t angle;
int32_t angle_loop;

static uint8_t *internal_dst_buffer;
static int32_t total_data_size = 64 * 1024 * 1024; // 64 MB for sustained access

void init_vars() {
    internal_dst_buffer = (uint8_t *)aligned_alloc(32, total_data_size);
    if (!internal_dst_buffer) {
        exit(1);
    }

    dst = internal_dst_buffer;
    stride = 64;
    v_cnt = 0;
    idx0 = 0;
    fact_val0 = 0;
    idx1 = 0;
    fact_val1 = 0;
    angle = 12345;
    angle_loop = 0;
}