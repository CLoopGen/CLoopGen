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
int32_t idx2;
int32_t fact_val2;
int32_t idx3;
int32_t fact_val3;
int32_t angle;
int32_t angle_loop;

static uint8_t *buffer;
static size_t total_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

void init_vars() {
    buffer = (uint8_t*)aligned_alloc(32, total_size);
    if (!buffer) {
        exit(1);
    }

    dst = buffer;
    stride = 16;
    v_cnt = 0;
    idx0 = 0;
    fact_val0 = 0;
    idx1 = 0;
    fact_val1 = 0;
    idx2 = 0;
    fact_val2 = 0;
    idx3 = 0;
    fact_val3 = 0;
    angle = 1 << 5;
    angle_loop = 0;
}