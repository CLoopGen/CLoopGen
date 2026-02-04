#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;

#define DATA_SIZE (128 * 1024 * sizeof(uint16_t))
static uint16_t dst_buffer[DATA_SIZE / sizeof(uint16_t)];
static uint16_t src_buffer[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    A = 42;
    h = 16384;
    stride = 8;

    dst = dst_buffer;
    src = src_buffer;

    for (int idx = 0; idx < DATA_SIZE / sizeof(uint16_t); idx++) {
        src_buffer[idx] = (uint16_t)(idx % 32768);
        dst_buffer[idx] = 0;
    }
}