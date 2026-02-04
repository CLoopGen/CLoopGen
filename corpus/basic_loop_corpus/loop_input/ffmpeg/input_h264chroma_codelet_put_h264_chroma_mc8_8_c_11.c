#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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
    stride = 64;
    h = DATA_SIZE / stride;
    dst = internal_dst;
    src = internal_src;
    A = 42;
    i = 0;

    for (int j = 0; j < DATA_SIZE; j++) {
        internal_src[j] = rand() % 256;
    }
}