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
int E;
int step;

uint8_t *dst_buffer;
uint8_t *src_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 MB for ~0.01 sec runtime estimate
    stride = 64; // typical cache-line aligned step
    h = data_size / stride;
    step = 1;

    A = 13;
    E = 19;
    i = 0;

    dst_buffer = (uint8_t*)aligned_alloc(64, data_size);
    src_buffer = (uint8_t*)aligned_alloc(64, data_size);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        src_buffer[idx] = rand() & 0xFF;
    }

    dst = dst_buffer;
    src = src_buffer;
}