#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int stride = 4;
int i;
uint16_t *dst;
int32_t *src;

static uint16_t dst_buffer[1024 * 1024];
static int32_t src_buffer[1024 * 1024];

void init_vars() {
    for (int j = 0; j < 1024 * 1024; j++) {
        dst_buffer[j] = (uint16_t)(j % 65535);
        src_buffer[j] = (int32_t)(j % 1000);
    }
    dst = dst_buffer;
    src = src_buffer;
}