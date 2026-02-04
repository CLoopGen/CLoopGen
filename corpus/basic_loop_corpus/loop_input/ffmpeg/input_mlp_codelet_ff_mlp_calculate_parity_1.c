#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

uint8_t *buf;
uint32_t scratch;
uint8_t *buf_end;

static uint8_t *internal_buf_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on typical CPU
    internal_buf_storage = (uint8_t *)aligned_alloc(32, data_size);
    if (!internal_buf_storage) {
        exit(1);
    }

    buf = internal_buf_storage;
    buf_end = internal_buf_storage + data_size;
    scratch = 0x12345678;

    // Initialize buffer with non-zero data to ensure meaningful operations
    for (size_t i = 0; i < data_size; i++) {
        internal_buf_storage[i] = (uint8_t)(i & 0xFF);
    }
}