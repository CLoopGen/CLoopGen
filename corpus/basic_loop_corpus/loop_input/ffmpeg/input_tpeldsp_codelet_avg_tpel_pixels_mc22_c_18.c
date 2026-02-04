#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define DATA_SIZE_MB 64
#define TOTAL_BYTES (DATA_SIZE_MB * 1024ULL * 1024)

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

static uint8_t buffer_src[TOTAL_BYTES];
static uint8_t buffer_dst[TOTAL_BYTES];

void init_vars() {
    width = 4096;
    height = (TOTAL_BYTES / width) / 2;
    if (height > 4096) height = 4096;
    stride = width + 16;

    src = buffer_src;
    dst = buffer_dst;

    for (size_t idx = 0; idx < TOTAL_BYTES; idx++) {
        buffer_src[idx] = rand() & 0xFF;
        buffer_dst[idx] = rand() & 0xFF;
    }

    i = 0;
    j = 0;
}