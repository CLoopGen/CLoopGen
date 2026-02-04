#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int y;
int size;
uint8_t *src;
uint8_t *left;
int dc;

static uint8_t *src_buffer;
static uint8_t *left_buffer;

void init_vars() {
    size = 16384;
    stride = 16384;
    dc = 42;

    src_buffer = (uint8_t*)calloc(size * stride, sizeof(uint8_t));
    left_buffer = (uint8_t*)calloc(size, sizeof(uint8_t));

    if (!src_buffer || !left_buffer) {
        exit(1);
    }

    src = src_buffer;
    left = left_buffer;
}