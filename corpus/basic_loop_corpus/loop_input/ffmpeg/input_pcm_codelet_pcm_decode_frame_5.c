#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int n;
uint8_t *samples;

static uint8_t *src_buffer;
static uint8_t *samples_buffer;

void init_vars() {
    size_t data_size = 128 << 20; // 128 MB
    src_buffer = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    samples_buffer = (uint8_t *)malloc(data_size * sizeof(uint8_t));

    if (!src_buffer || !samples_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    src = src_buffer;
    samples = samples_buffer;
    n = (int)data_size;
}