#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

uint8_t *src;
uint8_t *src_end;
FFTSample *xdat;
int tmp;

static uint8_t *src_buffer;
static FFTSample *xdat_buffer;
static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime on modern CPU

    src_buffer = (uint8_t *)aligned_alloc(32, data_size);
    xdat_buffer = (FFTSample *)aligned_alloc(32, data_size / sizeof(int) * sizeof(FFTSample));

    if (!src_buffer || !xdat_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i += sizeof(int)) {
        int val = rand();
        ((int *)(src_buffer + i))[0] = val;
    }

    src = src_buffer;
    src_end = src_buffer + data_size;
    xdat = xdat_buffer;
}