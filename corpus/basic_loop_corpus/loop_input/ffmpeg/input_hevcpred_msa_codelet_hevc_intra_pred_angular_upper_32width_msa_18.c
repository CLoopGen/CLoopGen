#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *ref_tmp;
uint8_t *src_left_tmp;
int32_t h_cnt;
int32_t inv_angle_val;
int32_t inv_angle_val_loop;
int32_t last;
int32_t offset;

static uint8_t ref_buffer[131072];
static uint8_t src_left_buffer[131072];

void init_vars() {
    ref_tmp = ref_buffer;
    src_left_tmp = src_left_buffer;
    last = 0;
    inv_angle_val = 256;
    inv_angle_val_loop = 0;
}