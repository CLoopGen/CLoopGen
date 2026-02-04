#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int size;
uint8_t *dst;
int dsize;

static uint8_t src_buffer[134217728]; // 128 MB
static uint8_t dst_buffer[134217728]; // 128 MB

void init_vars() {
    src = src_buffer;
    dst = dst_buffer;
    size = sizeof(src_buffer);
    dsize = 0;
}