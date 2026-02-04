#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *buf;
uint32_t scratch;
uint8_t *buf_end;

static uint8_t *internal_buf;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on typical CPU

    internal_buf = (uint8_t *)malloc(data_size);
    if (!internal_buf) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        internal_buf[i] = (uint8_t)(i & 0xFF);
    }

    buf = internal_buf;
    buf_end = internal_buf + data_size;
    scratch = 0;
}