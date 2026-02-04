#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (64 * 1024 * 1024)

uint8_t *src;
int *dst;
int scale;
int i;

void init_vars() {
    src = (uint8_t*)aligned_alloc(32, DATA_SIZE);
    dst = (int*)aligned_alloc(32, DATA_SIZE * sizeof(int));
    if (!src || !dst) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < DATA_SIZE; j++) {
        src[j] = (uint8_t)(j % 256);
    }
    for (size_t j = 0; j < DATA_SIZE; j++) {
        dst[j] = 0;
    }

    scale = 10;
    i = 0;
}