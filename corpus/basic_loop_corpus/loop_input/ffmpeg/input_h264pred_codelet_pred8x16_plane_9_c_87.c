#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int stride = 16;

uint16_t * src0;
uint16_t * src1;
uint16_t * src2;

int H = 0;
int V = 0;

static uint16_t * buffer = NULL;
static size_t total_size = 1 << 20; // ~1MB of data

void init_vars() {
    buffer = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!buffer) {
        exit(1);
    }

    src0 = buffer + 4; // ensure at least 4 elements before and after
    src1 = buffer + 512;
    src2 = buffer + 1024;

    for (size_t i = 0; i < total_size; ++i) {
        buffer[i] = (uint16_t)(i % 37);
    }
}