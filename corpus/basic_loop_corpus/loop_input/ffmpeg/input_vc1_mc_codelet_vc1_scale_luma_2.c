#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *srcY;
int k;
int linesize;
int i;
int j;

static uint8_t *buffer;

void init_vars() {
    k = 512;
    linesize = 1024;
    int total_size = k * linesize;
    buffer = (uint8_t*)aligned_alloc(64, total_size);
    if (!buffer) {
        exit(1);
    }
    srcY = buffer;
    for (int idx = 0; idx < total_size; idx++) {
        buffer[idx] = rand() % 256;
    }
}