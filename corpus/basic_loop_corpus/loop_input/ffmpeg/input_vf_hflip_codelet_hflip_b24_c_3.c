#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int w;
uint8_t *in;
uint8_t *out;
int j;

static uint8_t *in_buffer;
static uint8_t *out_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    in_buffer = (uint8_t *)aligned_alloc(32, data_size);
    out_buffer = (uint8_t *)aligned_alloc(32, data_size);

    if (!in_buffer || !out_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        in_buffer[i] = (uint8_t)(i & 0xFF);
    }

    in = in_buffer + data_size - 3; // point to last 3 bytes initially
    out = out_buffer;
    w = data_size / 3; // number of 3-byte groups to process
}