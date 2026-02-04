#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t sstride;
int h;
int a;
int b;
int x;
int y;
uint8_t *tmp;

static uint8_t *src_buffer;
static uint8_t *tmp_buffer;

void init_vars() {
    h = 16384; 
    a = 5;
    b = 3;
    sstride = 32;

    size_t src_size = (h + 1) * sstride;
    size_t tmp_size = (h + 1) * 16;

    src_buffer = (uint8_t*)aligned_alloc(32, src_size);
    tmp_buffer = (uint8_t*)aligned_alloc(32, tmp_size);

    if (!src_buffer || !tmp_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < src_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (size_t i = 0; i < tmp_size; i++) {
        tmp_buffer[i] = 0;
    }

    src = src_buffer;
    tmp = tmp_buffer;
}