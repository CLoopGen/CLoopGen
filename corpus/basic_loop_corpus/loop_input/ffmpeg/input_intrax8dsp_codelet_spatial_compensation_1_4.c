#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t total_data_size = 1 << 20; // 1MB

void init_vars() {
    src_buffer = (uint8_t *)calloc(total_data_size, sizeof(uint8_t));
    dst_buffer = (uint8_t *)calloc(total_data_size, sizeof(uint8_t));

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < total_data_size; i++) {
        src_buffer[i] = rand() % 256;
    }

    src = src_buffer + (8 + 8 + 1); // Base offset to ensure indexing from (8+8+1) is valid
    dst = dst_buffer;
    stride = 8; // Each row advances dst by 8 bytes
}