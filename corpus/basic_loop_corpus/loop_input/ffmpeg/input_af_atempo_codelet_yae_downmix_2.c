#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

uint8_t *src;
uint8_t *src_end;
FFTSample *xdat;
int16_t tmp;

static uint8_t *src_buffer;
static FFTSample *xdat_buffer;
static size_t data_size;

void init_vars() {
    data_size = 128 * 1024 * 1024; // 128 MB of input data for ~0.01 sec runtime

    src_buffer = (uint8_t *)aligned_alloc(32, data_size);
    xdat_buffer = (FFTSample *)aligned_alloc(32, data_size);

    if (!src_buffer || !xdat_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(int16_t); ++i) {
        ((int16_t *)src_buffer)[i] = (int16_t)(i & 0xFFFF);
    }

    src = src_buffer;
    src_end = src_buffer + data_size;
    xdat = xdat_buffer;
}