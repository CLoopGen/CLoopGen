#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int stride;
int h;
int rounder;
int A;
int B;
int C;
int D;
int i;

#define DATA_SIZE (128 * 1024 * 1024) // 128 MB total data
#define WIDTH 8
static uint8_t *src_buffer;
static uint8_t *dst_buffer;

void init_vars() {
    src_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    dst_buffer = (uint8_t*)aligned_alloc(32, DATA_SIZE);

    if (!src_buffer || !dst_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        src_buffer[idx] = rand() & 0xFF;
        dst_buffer[idx] = 0;
    }

    A = 17;
    B = 23;
    C = 19;
    D = 29;
    rounder = 128;
    stride = WIDTH + 2; // Ensure we have padding to prevent out-of-bounds access
    h = (DATA_SIZE / stride) - 1; // Adjust h so that src[stride + 8] is valid

    if (h <= 0) {
        h = 1;
    }

    src = src_buffer + 1; // Offset by 1 to allow src[-1] if needed, but our loop uses positive indices only
    dst = dst_buffer;
}