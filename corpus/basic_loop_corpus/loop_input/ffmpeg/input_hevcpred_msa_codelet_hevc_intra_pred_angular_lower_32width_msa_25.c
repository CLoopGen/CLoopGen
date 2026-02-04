#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

int32_t h_cnt;
int32_t inv_angle_val;
int32_t offset;
uint8_t *ref_tmp;
uint8_t *src_top_tmp;
int32_t last;

static uint8_t ref_buffer[16777216]; // 16 MB
static uint8_t src_top_buffer[16777216]; // 16 MB

void init_vars() {
    inv_angle_val = 256;
    last = 0;

    ref_tmp = ref_buffer;
    src_top_tmp = src_top_buffer;

    memset(ref_tmp, 0, sizeof(ref_buffer));
    memset(src_top_tmp, 0x55, sizeof(src_top_buffer));
}