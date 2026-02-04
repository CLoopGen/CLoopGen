#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t src_buffer[256 * 1024 * 1024]; // 256 MB buffer for src
static uint8_t dst_buffer[256 * 1024 * 1024]; // 256 MB buffer for dst

void init_vars() {
    src = src_buffer;
    dst = dst_buffer;
    stride = 8; // ensures each row moves by 8 bytes

    for (int i = 0; i < 256 * 1024 * 1024; i++) {
        src_buffer[i] = rand() % 256;
        dst_buffer[i] = 0;
    }
}