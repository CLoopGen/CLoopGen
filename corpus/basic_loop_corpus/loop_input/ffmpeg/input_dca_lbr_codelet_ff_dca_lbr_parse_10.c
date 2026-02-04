#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct GetByteContext {
    const uint8_t *buffer;
    const uint8_t *buffer_end;
    const uint8_t *buffer_start;
} GetByteContext;

static uint8_t *buffer_data;
GetByteContext gb;
int i;
int chunk_len;
uint16_t res;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB for ~0.01 sec runtime on modern CPU
    buffer_data = (uint8_t *)malloc(data_size);
    if (!buffer_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        buffer_data[idx] = (uint8_t)(idx & 0xFF);
    }

    gb.buffer_start = buffer_data;
    gb.buffer = gb.buffer_start;
    gb.buffer_end = gb.buffer_start + data_size;

    chunk_len = (int)(data_size > 2 ? data_size : 3); // Ensure at least 3 elements to satisfy loop condition
    res = 0;
}