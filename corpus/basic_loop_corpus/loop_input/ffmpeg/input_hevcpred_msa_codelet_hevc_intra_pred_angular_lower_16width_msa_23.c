#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t h_cnt;
int32_t inv_angle_val;
int32_t offset;
uint8_t *ref_tmp;
uint8_t *src_top_tmp;
int32_t last;

static uint8_t ref_buffer[1 << 20]; // 1MB buffer
static uint8_t src_top_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    inv_angle_val = 256;
    last = 0;
    ref_tmp = ref_buffer;
    src_top_tmp = src_top_buffer;
}