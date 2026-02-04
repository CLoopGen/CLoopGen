#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t dstride;
int h;
int c;
int d;
int x;
int y;
uint8_t *tmp;

static uint8_t *dst_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    h = 65536;  
    dstride = 4;
    c = 5;
    d = 3;

    size_t dst_size = (size_t)h * (size_t)dstride;
    size_t tmp_size = dst_size + 4;

    dst_buffer = aligned_alloc(32, dst_size);
    tmp_buffer = aligned_alloc(32, tmp_size);

    if (!dst_buffer || !tmp_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    dst = dst_buffer;
    tmp = tmp_buffer;

    for (size_t i = 0; i < tmp_size; i++) {
        tmp[i] = rand() & 0xFF;
    }
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}