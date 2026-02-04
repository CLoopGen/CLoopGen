#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

uint8_t *src;
uint8_t *src_end;
FFTSample *xdat;
uint8_t tmp;

static uint8_t *src_buffer;
static FFTSample *xdat_buffer;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; 

    src_buffer = (uint8_t *)aligned_alloc(32, data_size);
    xdat_buffer = (FFTSample *)aligned_alloc(32, data_size * sizeof(FFTSample));

    if (!src_buffer || !xdat_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = (uint8_t)(i & 0xFF);
    }

    src = src_buffer;
    src_end = src_buffer + data_size;
    xdat = xdat_buffer;
}