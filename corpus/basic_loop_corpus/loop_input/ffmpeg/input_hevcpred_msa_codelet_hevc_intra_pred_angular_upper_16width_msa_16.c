#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t h_cnt;
int32_t offset;
int32_t inv_angle_val;
int32_t inv_angle_val_loop;
uint8_t *ref_tmp;
uint8_t *src_left_tmp;
int32_t last;

static uint8_t ref_buffer[1 << 20]; // 1MB buffer
static uint8_t src_left_buffer[1 << 20]; // 1MB buffer

void init_vars() {
    h_cnt = 0;
    offset = 0;
    inv_angle_val = 256;
    inv_angle_val_loop = -128;
    last = 0;
    for (int i = 0; i < (1 << 20); i++) {
        src_left_buffer[i] = rand() & 0xFF;
    }
    ref_tmp = ref_buffer;
    src_left_tmp = src_left_buffer;
}