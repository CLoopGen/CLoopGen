#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define DATA_SIZE_MB 64

uint8_t *dst;
uint8_t *src;
int stride;
int width;
int height;
int i;
int j;

void init_vars() {
    width = 1920;
    height = 1080;
    stride = width + 32;

    size_t total_size = (size_t)stride * height * sizeof(uint8_t);

    src = (uint8_t*)aligned_alloc(32, total_size);
    dst = (uint8_t*)aligned_alloc(32, total_size);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; idx++) {
        src[idx] = rand() % 256;
    }

    memset(dst, 0, total_size);
}