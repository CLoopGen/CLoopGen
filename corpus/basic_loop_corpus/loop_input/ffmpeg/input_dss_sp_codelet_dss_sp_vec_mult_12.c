#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *src;
int32_t *dst;
int16_t *mult;
int i;

static int32_t *src_buf;
static int32_t *dst_buf;
static int16_t *mult_buf;

void init_vars() {
    size_t data_size = 1 << 20;
    src_buf = (int32_t*)calloc(data_size, sizeof(int32_t));
    dst_buf = (int32_t*)calloc(data_size, sizeof(int32_t));
    mult_buf = (int16_t*)calloc(data_size, sizeof(int16_t));

    for (size_t idx = 0; idx < data_size; idx++) {
        src_buf[idx] = (int32_t)(rand() % 65536) - 32768;
        mult_buf[idx] = (int16_t)(rand() % 65536) - 32768;
    }

    src = src_buf;
    dst = dst_buf;
    mult = mult_buf;
    i = 0;
}