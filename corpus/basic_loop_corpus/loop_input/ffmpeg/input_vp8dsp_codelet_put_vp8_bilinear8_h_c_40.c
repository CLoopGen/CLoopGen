#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
uint8_t *src;
ptrdiff_t sstride;
int h;
int a;
int b;
int x;
int y;

#define DATA_SIZE_MB 64
#define BUFFER_SIZE (DATA_SIZE_MB * 1024 * 1024)

static uint8_t dst_buffer[BUFFER_SIZE];
static uint8_t src_buffer[BUFFER_SIZE];

void init_vars() {
    const int width = 8;
    h = BUFFER_SIZE / width;
    dstride = width;
    sstride = width;
    a = 3;
    b = 5;

    dst = dst_buffer;
    src = src_buffer;
}