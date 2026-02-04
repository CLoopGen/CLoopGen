#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
uint16_t *src;
int h = 32768;
int stride = 16;
int scale = 2;
unsigned int dc = 100;
int i;

static uint16_t src_buffer[32768 * 16];
static uint16_t dst_buffer[32768 * 16];

void init_vars() {
    src = src_buffer;
    dst = dst_buffer;

    for (int idx = 0; idx < 32768 * 16; idx++) {
        src_buffer[idx] = rand() & 0xFFFF;
        dst_buffer[idx] = 0;
    }
}