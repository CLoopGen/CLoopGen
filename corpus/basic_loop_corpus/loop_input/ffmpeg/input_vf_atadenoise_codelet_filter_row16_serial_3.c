#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w = 16384;
int mid = 8;
int size = 16;
int thra = 10;
int thrb = 20;

uint16_t *src;
uint16_t **srcf;
uint16_t *dst;

void init_vars() {
    const size_t data_size = (size_t)w * sizeof(uint16_t);
    const size_t ptr_array_size = (size_t)size * sizeof(uint16_t*);

    src = (uint16_t*)aligned_alloc(32, data_size);
    dst = (uint16_t*)aligned_alloc(32, data_size);
    srcf = (uint16_t**)aligned_alloc(32, ptr_array_size);

    if (!src || !dst || !srcf) {
        fprintf(stderr, "Allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        srcf[i] = (uint16_t*)aligned_alloc(32, data_size);
        if (!srcf[i]) {
            fprintf(stderr, "Allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    srand((unsigned int)time(NULL));
    for (int x = 0; x < w; x++) {
        src[x] = (uint16_t)(rand() % 256);
        dst[x] = 0;
        for (int i = 0; i < size; i++) {
            srcf[i][x] = (uint16_t)(rand() % 256);
        }
    }
}