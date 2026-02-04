#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
uint32_t scratch;
uint8_t *buf_end;

static uint8_t *internal_buf;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU
    internal_buf = (uint8_t *)aligned_alloc(4, data_size);
    if (!internal_buf) {
        exit(1);
    }

    buf = internal_buf;
    buf_end = internal_buf + data_size - 3; // Ensure buf < buf_end - 3 is valid
    scratch = 0x12345678;

    // Initialize buffer with non-zero data to ensure meaningful XOR operations
    for (size_t i = 0; i < data_size; ++i) {
        internal_buf[i] = (uint8_t)(i & 0xFF);
    }
}