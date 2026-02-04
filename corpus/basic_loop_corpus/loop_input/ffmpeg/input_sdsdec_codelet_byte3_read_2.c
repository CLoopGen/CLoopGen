#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint32_t *dst;
int i;

static uint8_t src_buf[120];
static uint32_t dst_buf[40];

void init_vars() {
    src = src_buf;
    dst = dst_buf;
    for (int j = 0; j < 120; j++) {
        src[j] = (uint8_t)(j * 71 % 251);
    }
}