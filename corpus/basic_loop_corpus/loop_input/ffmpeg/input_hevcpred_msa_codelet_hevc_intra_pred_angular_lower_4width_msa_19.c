#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src_top;
uint8_t *ref_tmp;
int32_t last;
int32_t offset;
int32_t h_cnt;
int32_t inv_angle_val;

static uint8_t *src_storage;
static uint8_t *ref_storage;
static size_t data_size = 64 * 1024 * 1024; // 64 MB for sufficient runtime (~0.01 sec)

void init_vars() {
    src_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    ref_storage = (uint8_t*)calloc(data_size, sizeof(uint8_t));

    if (!src_storage || !ref_storage) {
        exit(1);
    }

    src_top = src_storage + data_size / 2;
    ref_tmp = ref_storage + data_size / 2;

    last = -100000;
    inv_angle_val = 256;

    for (int i = 0; i < data_size; i++) {
        src_storage[i] = (uint8_t)(i & 0xFF);
    }
}