#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int w;
uint16_t *src;
uint16_t *f1;
uint16_t *f2;
uint16_t *dst;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of total data to process
    w = data_size / sizeof(uint16_t);

    src = (uint16_t*)aligned_alloc(32, data_size);
    f1  = (uint16_t*)aligned_alloc(32, data_size);
    f2  = (uint16_t*)aligned_alloc(32, data_size);
    dst = (uint16_t*)aligned_alloc(32, data_size);

    if (!src || !f1 || !f2 || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < w; i++) {
        src[i] = (uint16_t)(rand() % 65536);
        f1[i]  = (uint16_t)(rand() % 65536);
        f2[i]  = (uint16_t)(rand() % 65536);
        dst[i] = 0;
    }
}