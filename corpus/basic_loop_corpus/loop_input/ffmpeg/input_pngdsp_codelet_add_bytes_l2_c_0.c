#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w;
long i;

static size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

void init_vars() {
    dst = aligned_alloc(sizeof(long), data_size);
    src1 = aligned_alloc(sizeof(long), data_size);
    src2 = aligned_alloc(sizeof(long), data_size);

    if (!dst || !src1 || !src2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        src1[j] = rand() % 256;
        src2[j] = rand() % 256;
    }

    w = (int)(data_size - sizeof(long)); // Ensure loop does not overflow
}