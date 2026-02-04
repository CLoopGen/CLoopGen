#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int16_t *dst;
int32_t width8mult;
int32_t cnt;

static uint8_t src_data[131072];
static int16_t dst_data[131072 / 8 * 8];

void init_vars() {
    src = src_data;
    dst = dst_data;
    width8mult = 131072 / 8;
    cnt = width8mult;
}