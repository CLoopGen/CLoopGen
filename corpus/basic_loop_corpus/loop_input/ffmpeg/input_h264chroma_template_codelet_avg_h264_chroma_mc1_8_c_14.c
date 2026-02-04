#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    stride = 64; // reasonable cache-line multiple
    h = (DATA_SIZE / stride) - 1; // ensure we don't overflow on last access
    dst = internal_dst;
    src = internal_src;
    A = 42; // arbitrary coefficient
    i = 0;
}