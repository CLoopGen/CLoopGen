#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint16_t *dst_buffer;
static uint16_t *src_buffer;

void init_vars() {
    // Initialize A to a reasonable constant value
    A = 42;

    // Set height to control loop iterations
    h = 16384;

    // Stride is in units of uint16_t, set to 1024 for spatial locality and alignment
    stride = 1024;

    // Allocate large buffers to ensure meaningful runtime (~0.01 sec on modern CPU)
    dst_buffer = (uint16_t*)aligned_alloc(64, DATA_SIZE);
    src_buffer = (uint16_t*)aligned_alloc(64, DATA_SIZE);

    if (!dst_buffer || !src_buffer) {
        exit(1);
    }

    // Initialize buffer contents to avoid undefined behavior
    for (int j = 0; j < (DATA_SIZE / sizeof(uint16_t)); j++) {
        dst_buffer[j] = j & 0xFFFF;
        src_buffer[j] = (j + 100) & 0xFFFF;
    }

    // Initialize dst and src pointers to start of buffers
    dst = dst_buffer;
    src = src_buffer;
}